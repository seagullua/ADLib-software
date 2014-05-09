import os
import sys

adlib = os.path.join(os.path.dirname(__file__), '../../libraries/ADLib/buildutil');
sys.path.append(adlib)

from BMFont import *

def generateFont(font_name):
    without_shadow = lambda x: renderText(x, font_name+'.ttf', 70, 'white')
    createBMFontForSymbols(u'1234567890', without_shadow, font_name+'.fnt',font_name+'.png', output_dir='.')

generateFont('Fredoka One')
generateFont('Lasco-Bold')


