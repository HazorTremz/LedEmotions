import vlc
import pafy
import re, urllib.parse, urllib.request
import random
import tkinter as tk
from song_importer import SongManager
import time
import math

class PlaySong:

    def __init__(self):
        self.chosen_song = None
        self.duration = None
        self.video = None
        self.media = None

    def search(self, name, n):
        query_string = urllib.parse.urlencode({"search_query": name})
        formatUrl = urllib.request.urlopen("https://www.youtube.com/results?" + query_string)
        search_results = re.findall(r"watch\?v=(\S{11})", formatUrl.read().decode())
        clip2 = "https://www.youtube.com/watch?v=" + "{}".format(search_results[0])
        self.video = pafy.new(clip2)
        if n == 1:
            videolink = self.video.getbest()
            print("* Video is playing *")
        else:
            videolink = self.video.getbestaudio()
            print("* Audio is playing *")

        self.media = vlc.MediaPlayer(videolink.url)
        self.play()
        time.sleep(5)
        # self.duration = math.ceil((self.media.get_length()*0.001/60))
        self.duration = math.ceil(self.media.get_length())


    def gui(self, song):
        m = tk.Tk()
        m.title("play n pause interface")
        self.start_button = tk.Button(m, text="play", width=10, height=2, command=lambda: [self.search(song, 2)])
        stop_button = tk.Button(m, text="stop", width=10, height=2, command=lambda: [self.stop()])
        pause_button = tk.Button(m, text="pause & play ", width=10, height=2, command=lambda: [self.pause()])
        next_button = tk.Button(m, text="next", width=10, height=2, command=lambda: [self.next()])
        self.start_button.pack()
        stop_button.pack()
        pause_button.pack()
        next_button.pack()
        m.mainloop()

    def play(self):
        self.media.play()


    def stop(self):
        self.media.stop()

    def pause(self):
        self.media.pause()

    def next(self,expression):
        self.stop()
        song = self.main('next',expression)
        self.search(song, 2)

    def main(self, para, expression):
        my_songs = SongManager()
        songs_to_play = my_songs.get_song()
        self.chosen_song = songs_to_play[random.randint(0, len(songs_to_play)-1)][expression]
        print("* NOW PLAYING :- *")
        print(str(self.chosen_song))

        if para == 'next':
            return self.chosen_song
        else:
            self.search(self.chosen_song, 2)




