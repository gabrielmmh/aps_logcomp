import pygame
import time

def play_midi(file_path):
    # Inicializa o mixer
    pygame.init()
    pygame.mixer.init()

    try:
        # Carrega o arquivo MIDI
        pygame.mixer.music.load(file_path)
        print(f"Tocando {file_path}")
    except pygame.error as e:
        print(f"Erro ao carregar o arquivo MIDI: {e}")
        return

    # Toca o arquivo MIDI
    pygame.mixer.music.play()

    # Espera até terminar
    while pygame.mixer.music.get_busy():
        time.sleep(1)

if __name__ == "__main__":
    # Altere 'output.mid' para o caminho do arquivo MIDI que deseja tocar
    play_midi("output.mid")
