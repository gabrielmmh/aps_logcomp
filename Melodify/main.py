import yaml
import mido
from parser import *
import subprocess

def main():
    with open('./ast.yaml', 'r') as f:
        ast = yaml.safe_load(f)
    ast_root = parse_ast(ast)

    # Initialize the context
    # context = {
    #     'tempo': 120,
    #     'instrument': 0,
    #     'variables': {},
    #     'functions': {},
    #     'track': mido.MidiTrack(),
    # }
    # # Create MIDI file
    # mid = mido.MidiFile()
    # mid.tracks.append(context['track'])
    # # Evaluate the AST
    # ast_root.evaluate(context)
    # # Save MIDI file
    # mid.save('output.mid')
    # print("MIDI file 'output.mid' has been generated.")

    # Generate Java code
    LoopNode.loop_counter = 0
    java_code = ast_root.generate_code()

    with open('GeneratedProgram.java', 'w') as f:
        f.write('\n'.join(java_code))
    print("Java source code generated as 'GeneratedProgram.java'")
    # Compile Java code
    subprocess.run(['javac', 'GeneratedProgram.java'], check=True)
    print("Java code compiled successfully.")
    # Run the Java program
    subprocess.run(['java', 'GeneratedProgram'], check=True)
    print("MIDI file 'output.mid' has been generated.")

if __name__ == '__main__':
    main()
