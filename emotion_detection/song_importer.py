import requests
import os

SHEET_ENDPOINT = os.environ.get("GS_ENDPOINT")
HEADERS = {
    "Authorization":os.environ.get("AUTH"),
    "Content-Type":"application/json",
}


class SongManager:
    # This class is responsible for talking to the Google Sheet.
    def __init__(self):
        self.response = requests.get(url=SHEET_ENDPOINT, headers=HEADERS)
        self.response.raise_for_status()

    def get_song(self):
        data = self.response.json()["sheet1"]
        return data

    def update_songs(self,row_id,song,type):
        changes = {
            "sheet1": {
                type:song,
            }
        }

        edit = requests.put(url=f"{SHEET_ENDPOINT}/{row_id}",json=changes,headers=HEADERS)
        edit.raise_for_status()





