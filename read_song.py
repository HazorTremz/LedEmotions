import pandas as pd
import random 
import play_audio



sheet = pd.read_excel("E:\led\music data.xlsx",usecols="{}".format("B"))

rows = int(sheet.shape[0])
song  = sheet.loc[random.randint(0,rows)][0]

print("* NOW PLAYING :- *")
print(str(song))
play = play_audio.play(song,2)






