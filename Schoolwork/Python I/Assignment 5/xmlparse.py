import xml.etree.ElementTree as et

tree = et.parse('cd_catalog.xml')

root = tree.getroot()

for i in root.findall('CD'):
    print("Artist: " + i.find('ARTIST').text,', Title: ' + i.find('TITLE').text, ', Decade: ' + i.find('DECADE').text)
