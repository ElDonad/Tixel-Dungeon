import random
import numpy as np
import colorama
from colorama import Fore, Back
import copy

colorama.init()

LEFT = 'lft'
RIGHT = 'rgt'
UP = 'up'
DOWN = 'dwn'

HORIZONTAL = 'horizontal'
VERTICAL = 'vertical'

class Room:
    def __init__(self, x=0, y=0, h=0, w=0):
        self.x = x
        self.y = y
        self.h = h
        self.w = w

class Path:
    def __init__(self, orientation = ''):
        self.straights = []
        self.orientation = orientation

    class Straight:
        def __init__(self, x=0, y=0, length = 0):
            self.x = x
            self.y = y
            self.length = length
        VERTICAL = -1
        HORIZONTAL = -2

        def getEnd(self):
            if self.orientation == VERTICAL:
                return (self.x, self.y + self.length)
            elif self.orientation == HORIZONTAL:
                return (self.x + self.length, self.y)

print("beginning...")
level = []
for x in range(50):
    level.append([])
    for y in range(50):
        level[x].append(".")
rooms = []
corridors = []

def generateLevel():
    levelX = 50
    levelY = 50
    hasKeyRoom = False
    hasItemRoom = False

    deltaFromCenter = 3

    roomNumber = random.randint(6,9)
    print(roomNumber)

    for roomIndex in range(roomNumber):
        placed = False
        placeIt = 0
        while placed == False:
            if placeIt > 1500:
                print("placement error")
                return False


            newRoom = Room()
            newRoom.h = random.randint(3,6)
            newRoom.w = random.randint(3,6)
            newRoom.x = random.randint(max(0, levelX / 2 - deltaFromCenter), min(levelX - newRoom.w - 1, levelX / 2 + deltaFromCenter))
            newRoom.y = random.randint(max(0, levelY / 2 - deltaFromCenter), min(levelY - newRoom.h - 1, levelY / 2 + deltaFromCenter))
            if not collide(newRoom):
                rooms.append(newRoom)
                if len(rooms) > 1:
                    corridors.append(generatePath(rooms[-1], rooms[-2]))
                placed = True
                deltaFromCenter += 5
                print("finished one room !")

def collide(sqr1):
    if isinstance(sqr1, Room):
        for sqr2 in rooms:
            if (sqr1.x + sqr1.w + 1>= sqr2.x - 1 and
                sqr1.x - 1<= sqr2.x + sqr2.w + 1 and
                sqr1.y + sqr1.h + 1>= sqr2.y - 1 and
                sqr1.y - 1<= sqr2.y + sqr2.h + 1
                ):
                return True
        return False

    elif isinstance(sqr1, Path):
        for straight in sqr1.straights:
            fakeSqr = Room()
            fakeSqr.x = straight.x
            fakeSqr.y = straight.y
            if straight.orientation == Path.Straight.HORIZONTAL:
                fakeSqr.w = straight.length
                fakeSqr.h = 1
            elif straight.orientation == Path.Straight.VERTICAL:
                fakeSqr.w = 1
                fakeSqr.h = straight.length
            if collide(fakeSqr):
                return True
        return False

def generatePath(room1, room2):
    startPoint = (0,0)
    endPoint = (0,0)

    def straightInDirection(direction, start = None, length=1, straight = Path.Straight()):

        if start == None:
            start = (straight.x, straight.y)
        x, y = start
        straight.x = x
        straight.y = y
        if direction == LEFT:
            straight.orientation = HORIZONTAL
            straight.length = -length
        elif direction == RIGHT:
            straight.orientation = HORIZONTAL
            straight.length = length
        elif direction == UP:
            straight.orientation = VERTICAL
            straight.length = -length
        elif direction == DOWN:
            straight.orientation = VERTICAL
            straight.length = length
        print("New path : ", start, length, direction)
        return straight


    initialDir = None

    initialiOrientation = None
    if abs(room1.x - room2.x) > abs(room1.y - room2.y):
        initialiOrientation = HORIZONTAL
    else:
        initialiOrientation = VERTICAL

    if initialiOrientation == HORIZONTAL:
        if room1.x > room2.x:
            initialDir = LEFT
        else:
            initialDir = RIGHT
    elif initialiOrientation == VERTICAL:
        if room1.y > room2.y:
            initialDir = UP
        else:
            initialDir = DOWN

    #Début de la génération : choisir un point de départ:
    if initialDir == LEFT:
        startPoint = (room1.x, random.randint(room1.y, room1.y + room1.h))
    elif initialDir == RIGHT:
        startPoint = (room1.x + room1.w, random.randint(room1.y, room1.y + room1.h))
    elif initialDir == UP:
        startPoint = (random.randint(room1.x, room1.x + room1.w), room1.y)
    elif initialDir == DOWN:
        startPoint = (random.randint(room1.x, room1.x + room1.w), room1.y + room1.h)
    print(startPoint)
    #input()

    #Choisir un point d'arrivée de la même manière: il doit être sur la face de la pièce opposée à celle du point de départ.
    if initialDir == LEFT:
        endPoint = (room2.x + room2.w, random.randint(room2.y, room2.y + room2.h))
    elif initialDir == RIGHT:
        endPoint = (room2.x, random.randint(room2.y, room2.y + room2.h))
    elif initialDir == UP:
        endPoint = (random.randint(room2.x, room2.x + room2.w), room2.y + room2.h)
    elif initialDir == DOWN:
        endPoint = (random.randint(room2.x, room2.x + room2.w), room2.y)
    print(endPoint)
    #input()

    path = Path()
    currentPos = startPoint
    headingDir = initialDir

    deltaDir = None
    priorityOrientation = None

    if initialDir == LEFT or initialDir == RIGHT:
        deltaDir = abs(startPoint[0] - endPoint[0])
        priorityOrientation = VERTICAL
    elif initialDir == UP or initialDir == DOWN:
        deltaDir = abs(startPoint[1] - endPoint[1])
        priorityOrientation = HORIZONTAL
    path.straights.append(copy.deepcopy(straightInDirection(initialDir, length = random.randint(1,max(1,int(deltaDir / 3))), start = currentPos)))
    currentPos = path.straights[-1].getEnd()
    print(currentPos)
    #input()
    while currentPos != endPoint:
        xDelta = abs(endPoint[0] - currentPos[0])
        xOffset = endPoint[0] - currentPos[0]
        yDelta = abs(endPoint[1] - currentPos[1])
        yOffset = endPoint[1] - currentPos[1]
        print("loop enter", xOffset, yOffset, priorityOrientation)
        #input()
        if yOffset != 0 and (priorityOrientation == VERTICAL or xOffset == 0):
            print("yOffset")
            newDirection = None
            if yOffset < 0:
                newDirection = UP
            elif yOffset > 0:
                newDirection = DOWN
            path.straights.append(copy.deepcopy(straightInDirection(newDirection, length=yDelta, start=currentPos)))
            currentPos = path.straights[-1].getEnd()
        elif xOffset != 0 and (priorityOrientation == HORIZONTAL or yOffset == 0):
            print("xOffset")
            newDirection = None
            if xOffset < 0:
                newDirection = LEFT
            elif xOffset > 0:
                newDirection = RIGHT
            print(newDirection)
            path.straights.append(copy.deepcopy(straightInDirection(newDirection, length=xDelta, start=currentPos)))
            currentPos = path.straights[-1].getEnd()
        else:
            print('nothing')
        print("ROAD ADVANCEMENT : currentPos : " + str(currentPos) + " endPos : " + str(endPoint))
        #input()
    return path

for a in range(0,1000):
    generateLevel()
    print("finished generation !")
    print(len(rooms))
    count = 1
    for room in rooms:
        for x in range(room.x, room.x + room.w):
            level[x][room.y] = str(count)#"░"
            level[x][room.y + room.h] = str(count)

        for y in range(room.y, room.y + room.h):
            level[room.x][y] = str(count)
            level[room.x + room.w][y] = str(count)

        count += 1

    print("nombre de corridors : ", len(corridors))
    for corridor in corridors:
        print("nombre de corridors : ", len(corridor.straights))
        for straight in corridor.straights:
            print("origine", straight.x, ', ',straight.y,"oritentation : ",straight.orientation, "length : ", straight.length)
            if straight.orientation == VERTICAL:
                for y in range(straight.y,straight.y + straight.length, np.sign(straight.length)):
                    for x in range(straight.x -1,straight.x + 1 + 1,2):
                        #level[x][y] = "░"
                        pass
                    level[straight.x][y]=Fore.RED + "." + Fore.WHITE

            elif straight.orientation == HORIZONTAL:
                print("horizontal")
                for x in range(straight.x,straight.x + straight.length, np.sign(straight.length)):
                    for y in range(straight.y -1,straight.y + 1 + 1,2):
                        #level[x][y] = "░"
                        pass
                    level[x][straight.y]= Fore.RED + "." + Fore.WHITE


    for line in level:
        lineC = " "
        print(lineC.join(line))

        rooms = []
        corridors = []
        level = []
        for x in range(50):
            level.append([])
            for y in range(50):
                level[x].append(".")
    print("loop position : ",a)
