import xml.etree.ElementTree as et
import xml.dom.minidom as xdm
import tkinter
import tkinter.messagebox

tree = et.parse('Nations.xml')
root = tree.getroot()

class nationAdder():
    def __init__(self):
        self.main_window = tkinter.Tk()

        self.top_frame = tkinter.Frame(self.main_window)
        self.mid_frame = tkinter.Frame(self.main_window)
        self.bottom_frame = tkinter.Frame(self.main_window)

        self.prompt_label = tkinter.Label(self.top_frame, text='Nation Adding')
 
        self.namePrompt = tkinter.Label(self.mid_frame, text='The name of of the Country you wish to enter. ')
        self.name_entry = tkinter.Entry(self.mid_frame, width=20)
        self.popPrompt = tkinter.Label(self.mid_frame, text='The population of of the Country you wish to enter. ')
        self.pop_entry = tkinter.Entry(self.mid_frame, width=20)
        self.contPrompt = tkinter.Label(self.mid_frame, text='Enter the continent the Country you wish to enter is on. ')
        self.cont_entry = tkinter.Entry(self.mid_frame, width=20)

        self.Conf_button = tkinter.Button(self.bottom_frame, text='Confirm', command=self.confirm)

        self.prompt_label.pack()
        self.namePrompt.pack()
        self.name_entry.pack()
        self.popPrompt.pack()
        self.pop_entry.pack()
        self.contPrompt.pack()
        self.cont_entry.pack()
        self.Conf_button.pack()

        self.top_frame.pack()
        self.mid_frame.pack()
        self.bottom_frame.pack()

        tkinter.mainloop()

    def confirm(self):
        
        name = (self.name_entry.get())
        population =  (self.pop_entry.get())
        continent = (self.cont_entry.get())

        name = str(name)
        population = str(population)
        continent = str(continent)

        coun = et.SubElement(root, 'COUNTRY')
        na = et.SubElement(coun, 'NAME')
        na.text = name
        pop = et.SubElement(coun, 'ITEM')
        pop.text = population
        cont = et.SubElement(coun, 'ITEM')
        cont.text = continent

        print(et.tostring(root))
        et.dump(root)

        dom3 = xdm.parse('Nations.xml')

        output = open('Nation2.xml', 'w')
        output.write(dom3.toprettyxml())
        output.close()

if __name__ == '__main__':
    msg = nationAdder()