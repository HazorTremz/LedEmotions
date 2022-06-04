from deepface import DeepFace
import cv2
import time


class Emotions:

    def __init__(self):
        self.time_factor = 0
        self.faceCascade = cv2.CascadeClassifier(cv2.data.haarcascades + "haarcascade_frontalface_default.xml")

        self.cap = cv2.VideoCapture(-1)

        if not self.cap.isOpened():
            self.cap = cv2.VideoCapture(0)
        else:
            raise IOError("Cannot open webcam")

    def check_emotion(self)->str:
        while self.time_factor < 5:
            time.sleep(1)
            try:
                ret, frame = self.cap.read()
                result = DeepFace.analyze(img_path=frame, actions=("emotion",))
                our_emotion = self.face_recon(frame,result)
            except ValueError:
                our_emotion = "neutral"
            if cv2.waitKey(2) and 0xFF == ord('q'):
                break
            self.time_factor += 1
        cv2.destroyAllWindows()

        return our_emotion

    def face_recon(self,box,attributes):
        gray = cv2.cvtColor(box, cv2.COLOR_BGR2GRAY)
        faces = self.faceCascade.detectMultiScale(gray, 1.1, 4)

        for (x, y, w, h) in faces:
            cv2.rectangle(box, (x, y), (x + w, y + h), (0, 255, 0), 2)

        font = cv2.FONT_HERSHEY_SCRIPT_SIMPLEX
        main_emotion = attributes["dominant_emotion"]
        cv2.putText(box,
                    main_emotion,
                    (50, 50),
                    font, 3,
                    (0, 0, 255),
                    2,
                    cv2.LINE_4)
        cv2.imshow("Video ", box)
        return main_emotion


