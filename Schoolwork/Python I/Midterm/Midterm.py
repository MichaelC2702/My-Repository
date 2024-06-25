import tkinter
import tkinter.messagebox

class MessageDesacratorGUI:
    def __init__(self):
        self.main_window = tkinter.Tk()

        self.top_frame = tkinter.Frame(self.main_window)
        self.mid_frame_input = tkinter.Frame(self.main_window)
        self.mid_frame = tkinter.Frame(self.main_window)
        self.bottom_frame = tkinter.Frame(self.main_window)

        self.prompt_label = tkinter.Label(self.top_frame, text='Character Extractor')
 
        self.text_entry = tkinter.Entry(self.mid_frame_input, width=20)

        self.prompt_label.pack()
        self.text_entry.pack()

        self.descr_label = tkinter.Label(self.mid_frame, text= 'Extracted Values:')
        self.value = tkinter.StringVar()
        self.miles_label = tkinter.Label(self.mid_frame, textvariable=self.value)
        self.descr_label.pack(side='left')
        self.miles_label.pack(side='left')
       

        self.Vowels_button = tkinter.Button(self.bottom_frame, text='Extract Vowels', command=self.convertV)
        self.Consonants_button = tkinter.Button(self.bottom_frame, text='Extract Consonants', command=self.convertC)
        self.Vowels_button.pack(side='left')
        self.Consonants_button.pack(side='left')

        self.top_frame.pack()
        self.mid_frame_input.pack()
        self.mid_frame.pack()
        self.bottom_frame.pack()
       

        tkinter.mainloop()

    def convertC(self):
        Text = (self.text_entry.get())

        Text2 = Text.translate({ord(a): None for a in "bBcCdDfFgGhHjJkKlLmMnNpPqQrRsStTvVwWxXyYzZ"})

        self.value.set(Text2)

    
    def convertV(self):
        Text = (self.text_entry.get())

       
        Text2 = Text.translate({ord(a): None for a in "aAeEiIoOuU"})


        self.value.set(Text2)


if __name__ == '__main__':
    msg = MessageDesacratorGUI()