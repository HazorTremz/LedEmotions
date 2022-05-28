import cv2
import matplotlib.pyplot as plt
from deepface import DeepFace
img = cv2.imread("happy boi.jpg")

# Command for creating the image
plt.imshow(cv2.cvtColor(img, cv2.COLOR_BGR2RGB))

# to analise the img for race,age and emotions
predictions = DeepFace.analyze(img)

# for detecting the face and making and rectangle around it

faceCascade = cv2.CascadeClassifier(cv2.data.haarcascades + "haarcascade_frontalface_default.xml")
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

faces = faceCascade.detectMultiScale(gray,1.1,4)

for (x,y,w,h) in faces:
    cv2.rectangle(img, (x,y), (x+w,y+h), (0,255,0), 2)

# for adding text to the image
font = cv2.FONT_HERSHEY_SIMPLEX

cv2.putText(img,
            predictions["dominant_emotion"],
            (0,100),
            font,1,
            (0,0,0),
            2,
            cv2.LINE_4)

plt.imshow(cv2.cvtColor(img, cv2.COLOR_BGR2RGB))
plt.show()