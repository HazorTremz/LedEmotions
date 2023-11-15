  <h1 align="center">Led Emotions</h1>
  <p align="center">
    It is a simple project which monitors your face and checks for any change in emotions every 5 secs. It picks a random song from your playlist contained under a particular emotion category and starts playing it via your audio output. An arduino along with some push buttons was used to provide manual access to refresh the current emotion or traverse through the song playlist attached with that emotion. A WS281B led strip was used to react to the audio and generate relative colours and patterns accordingly.
  <br>
</p>

## Libraries Required : 
  <p> 
  1. pyserial<br>
  2. deepface<br>
  3. opencv-python<br>
  4.vlc<br>
  5.pafy<br>
  6.re, urllib.parse, urllib.request<br>
  7. tkinter<br>
  </p>


## Setting up : 

  <p>
   1. Install the the required imports <br>
   2.Get your own auth key from <a href="https://sheety.co">Sheety</a> and make the required sheet for your emotion vs song
   3. Make the connections on arduino as given in code<br>
   4. Upload the given code on ur arudino<br>
   5. Run moodLighting.py<br>
  </p>
  
```bash
python3 moodLighting.py
```
