class Song:
    def __init__(self, lyrics):
        self.lyrics = lyrics
    def sing_me(self):
        for verse in self.lyrics:
            print(verse)

Let_go = Song(["When it's black, ", "Take a little time to hold yourself, ", "Take a little time to feel around, ", "Before it's gone!"])
Let_go.sing_me()