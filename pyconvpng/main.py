import sys
from data import Global
import xml.etree.ElementTree as ET
import parser



fileName = "conf.xml"
if len(sys.argv) > 1:
	fileName = sys.argv[1] + ".xml"

file = ET.parse(fileName)

for group in file.iter():


