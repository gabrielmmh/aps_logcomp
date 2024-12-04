from abc import ABC, abstractmethod
import mido

class Node(ABC):
    def __init__(self):
        self.children = []

    @abstractmethod
    def evaluate(self, context):
        pass

    @abstractmethod
    def generate_code(self, indent=''):
        pass

class ProgramNode(Node):
    def __init__(self, statements):
        super().__init__()
        self.statements = statements

    def evaluate(self, context):
        for stmt in self.statements:
            stmt.evaluate(context)

    def generate_code(self, indent=''):
        code = []
        code.append('import javax.sound.midi.*;')
        code.append('public class GeneratedProgram {')
        code.append('    static Sequence sequence;')
        code.append('    static Track track;')
        code.append('    static int tempo = 120;')
        code.append('    static int instrument = 0;')
        code.append('    static int volume = 64;')
        code.append('    static int tickPosition = 0;')

        # Collect all function declarations
        function_declarations = self.collect_function_declarations(self.statements)

        # Generate function declarations
        for func_decl in function_declarations:
            code.extend(func_decl.generate_code('    '))

        # Generate the main method
        code.append('    public static void main(String[] args) throws Exception {')
        code.append('        sequence = new Sequence(Sequence.PPQ, 480);')
        code.append('        track = sequence.createTrack();')
        code.append('        // User code begins here')

        # Remove function declarations from the statements
        non_function_statements = self.remove_function_declarations(self.statements)
        for stmt in non_function_statements:
            code.extend(stmt.generate_code('        '))

        code.append('        // User code ends here')
        code.append('        MidiSystem.write(sequence, 1, new java.io.File("output.mid"));')
        code.append('    }')
        code.append('}')
        return code

    def collect_function_declarations(self, statements):
        function_declarations = []
        for stmt in statements:
            if isinstance(stmt, FunctionDeclarationNode):
                function_declarations.append(stmt)
            elif hasattr(stmt, 'statements'):
                function_declarations.extend(self.collect_function_declarations(stmt.statements))
        return function_declarations

    def remove_function_declarations(self, statements):
        non_function_statements = []
        for stmt in statements:
            if isinstance(stmt, FunctionDeclarationNode):
                continue
            elif hasattr(stmt, 'statements'):
                stmt.statements = self.remove_function_declarations(stmt.statements)
                non_function_statements.append(stmt)
            else:
                non_function_statements.append(stmt)
        return non_function_statements
        

class StatementListNode(Node):
    def __init__(self, statements):
        super().__init__()
        self.statements = statements

    def evaluate(self, context):
        for stmt in self.statements:
            stmt.evaluate(context)

    def generate_code(self, indent=''):
        code = []
        for stmt in self.statements:
            code.extend(stmt.generate_code(indent))
        return code

class SetTempoNode(Node):
    def __init__(self, tempo):
        super().__init__()
        self.tempo = tempo

    def evaluate(self, context):
        context['tempo'] = self.tempo.evaluate(context)

    def generate_code(self, indent=''):
        tempo_value = self.tempo.generate_code()
        code = []
        code.append(f'{indent}tempo = {tempo_value};')
        code.append(f'{indent}MetaMessage tempoMessage = new MetaMessage();')
        code.append(f'{indent}int tempoSetting = 60000000 / tempo;')
        code.append(f'{indent}byte[] tempoBytes = new byte[] {{')
        code.append(f'{indent}    (byte)((tempoSetting >> 16) & 0xFF),')
        code.append(f'{indent}    (byte)((tempoSetting >> 8) & 0xFF),')
        code.append(f'{indent}    (byte)(tempoSetting & 0xFF)')
        code.append(f'{indent}}};')
        code.append(f'{indent}tempoMessage.setMessage(0x51, tempoBytes, 3);')
        code.append(f'{indent}track.add(new MidiEvent(tempoMessage, tickPosition));')
        return code

class SetInstrumentNode(Node):
    def __init__(self, instrument_name):
        super().__init__()
        self.instrument_name = instrument_name

    def evaluate(self, context):
        instrument_name = self.instrument_name.evaluate(context)
        instrument_map = {
            "piano": 0,
            "guitar": 26,
            "violin": 40,
            "harp": 46,
            "flute": 73,
            "organ": 19,  # Added organ
        }
        context['instrument'] = instrument_map.get(instrument_name.lower(), 0)
        program_change = mido.Message('program_change', program=context['instrument'])
        context['track'].append(program_change)

    def generate_code(self, indent=''):
        instrument_name = self.instrument_name.value
        instrument_map = {
            "piano": 0,
            "guitar": 24,
            "violin": 40,
            "harp": 46,
            "flute": 73,
            "organ": 19,
        }
        instrument_code = instrument_map.get(instrument_name.lower(), 0)
        code = []
        code.append(f'{indent}instrument = {instrument_code};')
        code.append(f'{indent}ShortMessage programChange = new ShortMessage();')
        code.append(f'{indent}programChange.setMessage(192, 0, instrument, 0);')
        code.append(f'{indent}track.add(new MidiEvent(programChange, tickPosition));')
        return code

class SetVolumeNode(Node):
    def __init__(self, volume):
        super().__init__()
        self.volume = volume

    def evaluate(self, context):
        context['volume'] = self.volume.evaluate(context)

    def generate_code(self, indent=''):
        volume_value = self.volume.generate_code()
        code = []
        code.append(f'{indent}volume = {volume_value};')
        return code

class FunctionDeclarationNode(Node):
    def __init__(self, name, parameters, body):
        super().__init__()
        self.name = name
        self.parameters = parameters
        self.body = body

    def evaluate(self, context):
        context['functions'][self.name] = self

    def generate_code(self, indent=''):
        code = []
        code.append(f'{indent}public static void {self.name}() throws Exception {{')
        code.extend(self.body.generate_code(indent + '    '))
        code.append(f'{indent}}}')
        return code

class FunctionCallNode(Node):
    def __init__(self, name, arguments):
        super().__init__()
        self.name = name
        self.arguments = arguments

    def evaluate(self, context):
        function = context['functions'].get(self.name)
        if function is None:
            raise Exception(f"Function '{self.name}' not defined")
        local_context = context.copy()
        local_context['variables'] = context['variables'].copy()
        function.body.evaluate(local_context)

    def generate_code(self, indent=''):
        code = []
        code.append(f'{indent}{self.name}();')
        return code

class VariableDeclarationNode(Node):
    def __init__(self, identifier, value):
        super().__init__()
        self.identifier = identifier
        self.value = value

    def evaluate(self, context):
        context['variables'][self.identifier.name] = self.value.evaluate(context)

    def generate_code(self, indent=''):
        if isinstance(self.value, NumberNode):
            var_type = "int"
        elif isinstance(self.value, StringNode):
            var_type = "String"
        elif isinstance(self.value, ExpressionNode):
            var_type = "int"
        else:
            raise Exception(f"Unsupported variable type for {self.identifier.name}")

        identifier_code = self.identifier.generate_code()
        value_code = self.value.generate_code()
        return [f'{indent}{var_type} {identifier_code} = {value_code};']


class PlayChordNode(Node):
    def __init__(self, chord_name, duration):
        super().__init__()
        self.chord_name = chord_name
        self.duration = duration

    def evaluate(self, context):
        chord_name = self.chord_name.evaluate(context)
        duration = self.duration.evaluate(context)
        note_numbers = chord_name_to_midi_numbers(chord_name)
        duration_ticks = duration_to_ticks(duration, context['tempo'])
        for note_number in note_numbers:
            msg_on = mido.Message('note_on', note=note_number, velocity=context.get('volume', 64))
            context['track'].append(msg_on)
        for note_number in note_numbers:
            msg_off = mido.Message('note_off', note=note_number, velocity=context.get('volume', 64), time=duration_ticks)
            context['track'].append(msg_off)

    def generate_code(self, indent=''):
        chord_name = self.chord_name.chord_name
        duration_value = self.duration.duration
        note_numbers = chord_name_to_midi_numbers(chord_name)
        duration_ticks = duration_to_ticks(duration_value)
        code = []
        code.append(f'{indent}// Play chord {chord_name}')
        for note_number in note_numbers:
            code.append(f'{indent}track.add(new MidiEvent(')
            code.append(f'{indent}    new ShortMessage(ShortMessage.NOTE_ON, 0, {note_number}, volume), tickPosition));')
        code.append(f'{indent}tickPosition += {duration_ticks};')
        for note_number in note_numbers:
            code.append(f'{indent}track.add(new MidiEvent(')
            code.append(f'{indent}    new ShortMessage(ShortMessage.NOTE_OFF, 0, {note_number}, volume), tickPosition));')
        return code

class PlayNoteNode(Node):
    def __init__(self, note, duration):
        super().__init__()
        self.note = note
        self.duration = duration

    def evaluate(self, context):
        note_value = self.note.evaluate(context)
        duration_value = self.duration.evaluate(context)
        note_number = note_to_midi_number(note_value)
        duration_ticks = duration_to_ticks(duration_value, context['tempo'])
        msg_on = mido.Message('note_on', note=note_number, velocity=context.get('volume', 64))
        context['track'].append(msg_on)
        msg_off = mido.Message('note_off', note=note_number, velocity=context.get('volume', 64), time=duration_ticks)
        context['track'].append(msg_off)

    def generate_code(self, indent=''):
        note_value = self.note.note
        duration_value = self.duration.duration
        midi_note = note_to_midi_number(note_value)
        duration_ticks = duration_to_ticks(duration_value)
        code = []
        code.append(f'{indent}// Play note {note_value}')
        code.append(f'{indent}track.add(new MidiEvent(')
        code.append(f'{indent}    new ShortMessage(ShortMessage.NOTE_ON, 0, {midi_note}, volume), tickPosition));')
        code.append(f'{indent}tickPosition += {duration_ticks};')
        code.append(f'{indent}track.add(new MidiEvent(')
        code.append(f'{indent}    new ShortMessage(ShortMessage.NOTE_OFF, 0, {midi_note}, volume), tickPosition));')
        return code

class NumberNode(Node):
    def __init__(self, value):
        super().__init__()
        self.value = value

    def evaluate(self, context):
        return self.value

    def generate_code(self, indent=''):
        return str(self.value)

class StringNode(Node):
    def __init__(self, value):
        super().__init__()
        self.value = value.strip('"')

    def evaluate(self, context):
        return self.value

    def generate_code(self, indent=''):
        return f'"{self.value}"'

class IdentifierNode(Node):
    def __init__(self, name):
        super().__init__()
        self.name = name

    def evaluate(self, context):
        if self.name in context['variables']:
            return context['variables'][self.name]
        elif self.name in context:
            return context[self.name]
        else:
            raise Exception(f"Variable '{self.name}' not found")

    def generate_code(self, indent=''):
        return self.name

class DurationNode(Node):
    def __init__(self, duration):
        super().__init__()
        self.duration = duration

    def evaluate(self, context):
        return self.duration

    def generate_code(self, indent=''):
        return f'"{self.duration}"'

class ChordNameNode(Node):
    def __init__(self, chord_name):
        super().__init__()
        self.chord_name = chord_name

    def evaluate(self, context):
        return self.chord_name

    def generate_code(self, indent=''):
        return f'"{self.chord_name}"'

class NoteNode(Node):
    def __init__(self, note):
        super().__init__()
        self.note = note

    def evaluate(self, context):
        return self.note

    def generate_code(self, indent=''):
        return self.note

class ConditionalNode(Node):
    def __init__(self, condition, if_block, else_block=None):
        super().__init__()
        self.condition = condition
        self.if_block = if_block
        self.else_block = else_block

    def evaluate(self, context):
        if self.condition.evaluate(context):
            self.if_block.evaluate(context)
        elif self.else_block:
            self.else_block.evaluate(context)

    def generate_code(self, indent=''):
        condition_code = self.condition.generate_code()
        code = []
        code.append(f'{indent}if {condition_code} {{')
        code.extend(self.if_block.generate_code(indent + '    '))
        code.append(f'{indent}}}')
        if self.else_block:
            code.append(f'{indent}else {{')
            code.extend(self.else_block.generate_code(indent + '    '))
            code.append(f'{indent}}}')
        return code

class LoopNode(Node):
    loop_counter = 0

    def __init__(self, iterations, body):
        super().__init__()
        self.iterations = iterations
        self.body = body
        self.loop_id = LoopNode.loop_counter
        LoopNode.loop_counter += 1

    def evaluate(self, context):
        iteration_count = self.iterations.evaluate(context)
        for _ in range(iteration_count):
            self.body.evaluate(context)

    def generate_code(self, indent=''):
        iteration_code = self.iterations.generate_code()
        loop_var = f'i{self.loop_id}'
        code = []
        code.append(f'{indent}for (int {loop_var} = 0; {loop_var} < {iteration_code}; {loop_var}++) {{')
        code.extend(self.body.generate_code(indent + '    '))
        code.append(f'{indent}}}')
        return code

class ConditionNode(Node):
    def __init__(self, left, right, operator):
        super().__init__()
        self.left = left
        self.right = right
        self.operator = operator

    def evaluate(self, context):
        left_value = self.left.evaluate(context)
        right_value = self.right.evaluate(context)
        if self.operator == '<':
            return left_value < right_value
        elif self.operator == '>':
            return left_value > right_value
        elif self.operator == '=':
            return left_value == right_value
        elif self.operator == '!':
            return left_value != right_value
        elif self.operator == '&':
            return left_value and right_value
        elif self.operator == '|':
            return left_value or right_value
        else:
            raise Exception(f"Unknown operator: {self.operator}")

    def generate_code(self, indent=''):
        left_code = self.left.generate_code()
        right_code = self.right.generate_code()
        op_map = {
            '<': '<',
            '>': '>',
            '=': '==',
            '!': '!=',
            '&': '&&',  # Corrigido para &&
            '|': '||'   # Corrigido para ||
        }
        operator = op_map.get(self.operator)
        if operator is None:
            raise Exception(f"Unknown operator: {self.operator}")
        return f'({left_code} {operator} {right_code})'

class ExpressionNode(Node):
    def __init__(self, left, right, operator):
        super().__init__()
        self.left = left
        self.right = right
        self.operator = operator

    def evaluate(self, context):
        left_value = self.left.evaluate(context)
        right_value = self.right.evaluate(context)
        if self.operator == '+':
            return left_value + right_value
        elif self.operator == '-':
            return left_value - right_value
        elif self.operator == '*':
            return left_value * right_value
        elif self.operator == '/':
            if right_value == 0:
                raise Exception("Division by zero")
            return left_value / right_value
        else:
            raise Exception(f"Unsupported operator: {self.operator}")

    def generate_code(self):
        left_code = self.left.generate_code()
        right_code = self.right.generate_code()
        return f'({left_code} {self.operator} {right_code})'


# Utility functions
def note_to_midi_number(note):
    note_map = {'C': 0, 'C#':1, 'D': 2, 'D#':3, 'E': 4, 'F': 5, 'F#':6,
                'G': 7, 'G#':8, 'A': 9, 'A#':10, 'B': 11}
    if len(note) == 2:
        key = note[0]
        octave = int(note[1])
    elif len(note) == 3:
        key = note[0:2]
        octave = int(note[2])
    else:
        raise Exception(f"Invalid note format: {note}")
    midi_number = (octave + 1) * 12 + note_map[key]
    return midi_number

def duration_to_ticks(duration):
    duration_map = {'whole': 1920, 'half': 960, 'quarter': 480, 'eighth': 240}
    return duration_map.get(duration, 480)

def chord_name_to_midi_numbers(chord_name):
    chords = {
        'C_major': ['C4', 'E4', 'G4'],
        'C_minor': ['C4', 'D#4', 'G4'],
        'D_major': ['D4', 'F#4', 'A4'],
        'D_minor': ['D4', 'F4', 'A4'],
        'E_major': ['E4', 'G#4', 'B4'],
        'E_minor': ['E4', 'G4', 'B4'],
        'F_major': ['F4', 'A4', 'C5'],
        'F_minor': ['F4', 'G#4', 'C5'],
        'G_major': ['G4', 'B4', 'D5'],
        'G_minor': ['G4', 'A#4', 'D5'],
        'A_major': ['A4', 'C#5', 'E5'],
        'A_minor': ['A4', 'C5', 'E5'],
        'B_major': ['B4', 'D#5', 'F#5'],
        'B_minor': ['B4', 'D5', 'F#5'],
    }
    notes = chords.get(chord_name)
    if not notes:
        raise Exception(f"Chord '{chord_name}' not recognized")
    return [note_to_midi_number(note) for note in notes]
