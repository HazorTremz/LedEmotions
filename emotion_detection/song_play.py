import pafy 
import vlc 
import re, urllib.parse, urllib.request
import pandas as pd
import random 
import tkinter as tk


class play_song:

    def __init__(self):
        pass

    def search(self,name,n):
        query_string   = urllib.parse.urlencode({"search_query": name})
        formatUrl      = urllib.request.urlopen("https://www.youtube.com/results?" + query_string)
        search_results = re.findall(r"watch\?v=(\S{11})", formatUrl.read().decode())
        clip2          = "https://www.youtube.com/watch?v=" + "{}".format(search_results[0])
        self.video     = pafy.new(clip2)
        if n==1:
           videolink   = self.video.getbest()
           print("* Video is playing *")
        else:
           videolink   = self.video.getbestaudio()  
           print("* Audio is playing *") 

        self.media = vlc.MediaPlayer(videolink.url) 
        self.play()   


    def gui(self,song):
        m = tk.Tk()
        m.title("play n pause interface")
        self.start_button = tk.Button(m , text = "play" ,         width = 10 , height = 2,  command = lambda:[self.search(song,2)])
        stop_button  = tk.Button(m , text = "stop" ,         width = 10 , height = 2,  command = lambda:[self.stop()])
        pause_button = tk.Button(m , text = "pause & play ", width = 10 , height = 2,  command = lambda:[self.pause()])
        next_button  = tk.Button(m , text = "next",          width = 10,  height =2,   command = lambda:[self.next()])
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

    def next(self):
        self.stop()
        song = self.main('next')
        self.search(song,2)
        



    def main(self,para):
        sheet = pd.read_excel("E:\led\music data.xlsx",usecols="{}".format("B"))
        rows = int(sheet.shape[0])
        song  = sheet.loc[random.randint(0,rows-1)][0]
        print("* NOW PLAYING :- *")
        print(str(song)) 

        if para == 'next' :
          return song   
        else :
          self.gui(song)   

       


play = play_song()
play.main('main')