from nodes import *

def parse_ast(ast_node):
    node_type = ast_node['type']
    if node_type == 0:  # NODE_PROGRAM
        statements = [parse_ast(ast_node['left'])] if ast_node.get('left') else []
        return ProgramNode(statements)
    elif node_type == 1:  # NODE_STATEMENT_LIST
        statements = []
        current = ast_node
        while current:
            statement = parse_ast(current['left'])
            statements.append(statement)
            current = current.get('next')
        return StatementListNode(statements)
    elif node_type == 3:  # NODE_VARIABLE_DECLARATION
        identifier = parse_ast(ast_node['left'])
        value = parse_ast(ast_node['right'])
        return VariableDeclarationNode(identifier, value)
    elif node_type == 4:  # NODE_ASSIGNMENT
        identifier = parse_ast(ast_node['left'])
        value = parse_ast(ast_node['right'])
        return AssignmentNode(identifier, value)
    elif node_type == 6:  # NODE_CONDITIONAL
        condition = parse_ast(ast_node['left'])
        if_block = parse_ast(ast_node.get('if_block')) if ast_node.get('if_block') else None
        else_block = parse_ast(ast_node.get('else_block')) if ast_node.get('else_block') else None
        return ConditionalNode(condition, if_block, else_block)
    elif node_type == 7:  # NODE_LOOP
        iterations = parse_ast(ast_node['left'])
        body = parse_ast(ast_node['right'])
        return LoopNode(iterations, body)
    elif node_type == 8:  # NODE_FUNCTION_DECLARATION
        name = parse_ast(ast_node['left'])
        body = parse_ast(ast_node['right'])
        return FunctionDeclarationNode(name.name, [], body)
    elif node_type == 9:  # NODE_FUNCTION_CALL
        name = parse_ast(ast_node['left'])
        arguments = []
        if ast_node.get('right'):
            arguments = parse_ast(ast_node['right'])
        return FunctionCallNode(name.name, arguments)
    elif node_type == 11:  # NODE_EXPRESSION
        left = parse_ast(ast_node['left'])
        right = parse_ast(ast_node['right'])
        operator = ast_node.get('operator')
        if operator is None:
            raise Exception("Operator not found in expression node")
        return ExpressionNode(left, right, operator)
    elif node_type == 16:  # NODE_CONDITION
        left = parse_ast(ast_node['left'])
        right = parse_ast(ast_node['right'])
        operator = ast_node.get('operator')  # Corrigir para buscar o campo 'operator'
        if operator is None:
            raise Exception("Operator not found in condition node")
        return ConditionNode(left, right, operator)
    elif node_type == 27:  # NODE_PLAY_NOTE
        note = parse_ast(ast_node['left'])
        duration = parse_ast(ast_node['right'])
        return PlayNoteNode(note, duration)
    elif node_type == 28:  # NODE_PLAY_CHORD
        chord = parse_ast(ast_node['left'])
        duration = parse_ast(ast_node['right'])
        return PlayChordNode(chord, duration)
    elif node_type == 17:  # NODE_IDENTIFIER
        return IdentifierNode(ast_node['value'])
    elif node_type == 18:  # NODE_NUM
        return NumberNode(ast_node['value'])
    elif node_type == 19:  # NODE_STRING
        return StringNode(ast_node['value'])
    elif node_type == 20:  # NODE_NOTE
        return NoteNode(ast_node['value'])
    elif node_type == 21:  # NODE_CHORD_NAME
        return ChordNameNode(ast_node['value'])
    elif node_type == 22:  # NODE_DURATION
        return DurationNode(ast_node['value'])
    elif node_type == 24:  # NODE_SET_TEMPO
        tempo = parse_ast(ast_node['left'])
        return SetTempoNode(tempo)
    elif node_type == 25:  # NODE_SET_INSTRUMENT
        instrument = parse_ast(ast_node['left'])
        return SetInstrumentNode(instrument)
    elif node_type == 26:  # NODE_SET_VOLUME
        volume = parse_ast(ast_node['left'])
        return SetVolumeNode(volume)
    else:
        raise Exception(f"Unknown node type: {node_type}")


