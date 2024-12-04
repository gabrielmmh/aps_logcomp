import javax.sound.midi.*;
public class GeneratedProgram {
    static Sequence sequence;
    static Track track;
    static int tempo = 120;
    static int instrument = 0;
    static int volume = 64;
    static int tickPosition = 0;
    public static void main(String[] args) throws Exception {
        sequence = new Sequence(Sequence.PPQ, 480);
        track = sequence.createTrack();
        // User code begins here
        tempo = 120;
        MetaMessage tempoMessage = new MetaMessage();
        int tempoSetting = 60000000 / tempo;
        byte[] tempoBytes = new byte[] {
            (byte)((tempoSetting >> 16) & 0xFF),
            (byte)((tempoSetting >> 8) & 0xFF),
            (byte)(tempoSetting & 0xFF)
        };
        tempoMessage.setMessage(0x51, tempoBytes, 3);
        track.add(new MidiEvent(tempoMessage, tickPosition));
        instrument = 0;
        ShortMessage programChange = new ShortMessage();
        programChange.setMessage(192, 0, instrument, 0);
        track.add(new MidiEvent(programChange, tickPosition));
        // Play note D#5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 75, volume), tickPosition));
        tickPosition += 240;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 75, volume), tickPosition));
        // Play note F#5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 78, volume), tickPosition));
        tickPosition += 240;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 78, volume), tickPosition));
        // Play note G#5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 80, volume), tickPosition));
        tickPosition += 240;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 80, volume), tickPosition));
        // Play note F#5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 78, volume), tickPosition));
        tickPosition += 240;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 78, volume), tickPosition));
        // Play note D#5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 75, volume), tickPosition));
        tickPosition += 480;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 75, volume), tickPosition));
        // Play note E5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 76, volume), tickPosition));
        tickPosition += 240;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 76, volume), tickPosition));
        // Play note F#5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 78, volume), tickPosition));
        tickPosition += 240;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 78, volume), tickPosition));
        // Play note G#5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 80, volume), tickPosition));
        tickPosition += 240;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 80, volume), tickPosition));
        // Play note B5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 83, volume), tickPosition));
        tickPosition += 240;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 83, volume), tickPosition));
        // Play note G#5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 80, volume), tickPosition));
        tickPosition += 480;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 80, volume), tickPosition));
        // Play note C#5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 73, volume), tickPosition));
        tickPosition += 240;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 73, volume), tickPosition));
        // Play note E5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 76, volume), tickPosition));
        tickPosition += 240;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 76, volume), tickPosition));
        // Play note F#5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 78, volume), tickPosition));
        tickPosition += 240;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 78, volume), tickPosition));
        // Play note A5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 81, volume), tickPosition));
        tickPosition += 240;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 81, volume), tickPosition));
        // Play note F#5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 78, volume), tickPosition));
        tickPosition += 480;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 78, volume), tickPosition));
        // Play note G#5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 80, volume), tickPosition));
        tickPosition += 240;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 80, volume), tickPosition));
        // Play note F#5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 78, volume), tickPosition));
        tickPosition += 240;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 78, volume), tickPosition));
        // Play note G#5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 80, volume), tickPosition));
        tickPosition += 240;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 80, volume), tickPosition));
        // Play note E5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 76, volume), tickPosition));
        tickPosition += 240;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 76, volume), tickPosition));
        // Play note F#5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 78, volume), tickPosition));
        tickPosition += 240;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 78, volume), tickPosition));
        // Play note G#5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 80, volume), tickPosition));
        tickPosition += 240;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 80, volume), tickPosition));
        // Play note F#5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 78, volume), tickPosition));
        tickPosition += 240;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 78, volume), tickPosition));
        // Play note E5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 76, volume), tickPosition));
        tickPosition += 240;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 76, volume), tickPosition));
        // Play note F#5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 78, volume), tickPosition));
        tickPosition += 240;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 78, volume), tickPosition));
        // Play note D#5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 75, volume), tickPosition));
        tickPosition += 240;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 75, volume), tickPosition));
        // Play note E5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 76, volume), tickPosition));
        tickPosition += 480;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 76, volume), tickPosition));
        // Play note G#5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 80, volume), tickPosition));
        tickPosition += 240;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 80, volume), tickPosition));
        // Play note F#5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 78, volume), tickPosition));
        tickPosition += 240;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 78, volume), tickPosition));
        // Play note E5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 76, volume), tickPosition));
        tickPosition += 240;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 76, volume), tickPosition));
        // Play note C#5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 73, volume), tickPosition));
        tickPosition += 240;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 73, volume), tickPosition));
        // Play note D#5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 75, volume), tickPosition));
        tickPosition += 240;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 75, volume), tickPosition));
        // Play note E5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 76, volume), tickPosition));
        tickPosition += 480;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 76, volume), tickPosition));
        // Play note A5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 81, volume), tickPosition));
        tickPosition += 240;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 81, volume), tickPosition));
        // Play note G#5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 80, volume), tickPosition));
        tickPosition += 240;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 80, volume), tickPosition));
        // Play note F#5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 78, volume), tickPosition));
        tickPosition += 240;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 78, volume), tickPosition));
        // Play note D#5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 75, volume), tickPosition));
        tickPosition += 240;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 75, volume), tickPosition));
        // Play note E5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 76, volume), tickPosition));
        tickPosition += 240;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 76, volume), tickPosition));
        // Play note F#5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 78, volume), tickPosition));
        tickPosition += 480;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 78, volume), tickPosition));
        // Play note F#5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 78, volume), tickPosition));
        tickPosition += 480;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 78, volume), tickPosition));
        // Play note G#5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 80, volume), tickPosition));
        tickPosition += 480;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 80, volume), tickPosition));
        // Play note B5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 83, volume), tickPosition));
        tickPosition += 960;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 83, volume), tickPosition));
        // Play note E5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 76, volume), tickPosition));
        tickPosition += 480;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 76, volume), tickPosition));
        // Play note F#5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 78, volume), tickPosition));
        tickPosition += 480;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 78, volume), tickPosition));
        // Play note G#5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 80, volume), tickPosition));
        tickPosition += 960;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 80, volume), tickPosition));
        // Play note C#5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 73, volume), tickPosition));
        tickPosition += 480;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 73, volume), tickPosition));
        // Play note E5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 76, volume), tickPosition));
        tickPosition += 480;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 76, volume), tickPosition));
        // Play note F#5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 78, volume), tickPosition));
        tickPosition += 960;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 78, volume), tickPosition));
        // Play note F#5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 78, volume), tickPosition));
        tickPosition += 480;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 78, volume), tickPosition));
        // Play note E5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 76, volume), tickPosition));
        tickPosition += 480;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 76, volume), tickPosition));
        // Play note D5
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_ON, 0, 74, volume), tickPosition));
        tickPosition += 960;
        track.add(new MidiEvent(
            new ShortMessage(ShortMessage.NOTE_OFF, 0, 74, volume), tickPosition));
        // User code ends here
        MidiSystem.write(sequence, 1, new java.io.File("output.mid"));
    }
}