
from PIL import Image,ImageFont,ImageDraw
import sys

width, height = (600, 600)

img = Image.new('RGBA',(height, width),'white')
strl = 'a'

#carregando arquivo
arquivo = open(sys.argv[1], "r")
n = int(arquivo.readline())
l = height/n

font = ImageFont.truetype('arial.ttf', int(0.8*l))
w, h = font.getsize(strl)


draw = ImageDraw.Draw(img)

for i in range(n):
    for j in range(n):
        line = arquivo.readline().split()
        if line[3]=='0':
            iscor = False
        else:
            iscor = True
        x = i*l
        y = j*l
        xx = l*i+(l-w)/2
        yy = l*j+(l-h)/2
        if iscor:
            draw.rectangle(((i*l, j*l), (l*(i+1), l*(j+1))), outline = 'grey' ,fill = 'white')
            draw.text((xx, yy), line[2], font=font, align = 'left', fill = "black")
        else:
            draw.rectangle(((i*l, j*l), (l*(i+1), l*(j+1))), outline = 'grey' ,fill = 'black')
            draw.text((xx, yy), line[2], font=font, align = 'left', fill = "white")
img.show()
