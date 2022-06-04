from arduino_communication import ArduinoCom
from song import PlaySong
from datetime import datetime
from emotions import Emotions


class MoodLighting:

    def __init__(self):
        self.express = None
        self.arduino = ArduinoCom()
        self.player = PlaySong()

    def state_execution(self):
        state = self.arduino.get_data()
        if state == "START":
            self.start_emotion()
        if state == "NEXT":
            print("*** next song ***")
            self.player.next(self.express)
            self.arduino.send_data(self.player.chosen_song)
        # pressing button for stopping
        if state == "STOP":
            self.player.stop()
        # pressing button for pause
        if state == "PAUSE":
            self.player.pause()
        # pressing button for play
        if state == "PLAY":
            self.player.play()

    def start_emotion(self):
        face = Emotions()
        self.express = face.check_emotion()
        try:
            self.player.stop()
        except AttributeError:
            print("*******"
                  "No Song is currently playing,Moving to:"
                  "******")
        self.player.main("main", self.express)
        self.arduino.send_data(self.player.chosen_song)

    def control_loop(self):
        while True:
            self.state_execution()
            try:
                if self.player.media.is_playing() == 0:
                    print("*** next song ***")
                    self.player.next(self.express)
            except AttributeError:
                pass


if __name__ == "__main__":
    mood_obj = MoodLighting()
    mood_obj.control_loop()

