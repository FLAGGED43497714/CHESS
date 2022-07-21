import pygame
import os


FPS = 60

WIDTH,HEIGHT = 600,600

COLUMNS,ROWS = 8,8

SQUARE = WIDTH/COLUMNS

PATH ='Classes\img'

#Images constants
WHITE_KNIGHT = pygame.transform.scale(pygame.image.load(os.path.join(PATH,'wKN.png')),(SQUARE - 10,SQUARE - 10))
WHITE_BISHOP = pygame.transform.scale(pygame.image.load(os.path.join(PATH,'wB.png')),(SQUARE - 10,SQUARE - 10))
WHITE_PAWN = pygame.transform.scale(pygame.image.load(os.path.join(PATH,'wP.png')),(SQUARE - 10,SQUARE - 10))
WHITE_ROOK = pygame.transform.scale(pygame.image.load(os.path.join(PATH,'wR.png')),(SQUARE - 10,SQUARE - 10))
WHITE_QUEEN = pygame.transform.scale(pygame.image.load(os.path.join(PATH,'wQ.png')),(SQUARE - 10,SQUARE - 10))
WHITE_KING = pygame.transform.scale(pygame.image.load(os.path.join(PATH,'wK.png')),(SQUARE - 10,SQUARE - 10))

BLACK_KNIGHT = pygame.transform.scale(pygame.image.load(os.path.join(PATH,'bKN.png')),(SQUARE - 10,SQUARE - 10))
BLACK_BISHOP = pygame.transform.scale(pygame.image.load(os.path.join(PATH,'bB.png')),(SQUARE - 10,SQUARE - 10))
BLACK_PAWN = pygame.transform.scale(pygame.image.load(os.path.join(PATH,'bP.png')),(SQUARE - 10,SQUARE - 10))
BLACK_ROOK = pygame.transform.scale(pygame.image.load(os.path.join(PATH,'bR.png')),(SQUARE - 10,SQUARE - 10))
BLACK_QUEEN = pygame.transform.scale(pygame.image.load(os.path.join(PATH,'bQ.png')),(SQUARE - 10,SQUARE - 10))
BLACK_KING = pygame.transform.scale(pygame.image.load(os.path.join(PATH,'bK.png')),(SQUARE - 10,SQUARE - 10))

#Colors for the board
WHITE = (200,200,200)
BLACK = (100,100,100)

#Hashing dictionary for the trace of the game
LETTERS = {
0:'a',
1:'b',
2:'c',
3:'d',
4:'e',
5:'f',
6:'g',
7:'h'
}
NUMBERS = {
    '0' : 0,
    '1' : 1,
    '2' : 2,
    '3' : 3,
    '4' : 4,
    '5' : 5,
    '6' : 6,
    '7' : 7,
    '8' : 8,
    '9' : 9
}
SQUARES_INDEX = {
    'a': 0,
    'b': 1,
    'c': 2,
    'd': 3,
    'e': 4,
    'f': 5,
    'g': 6,
    'h': 7
    }
PIECES_FEN = {
    'White_Rook' : 'R',
    'White_Bishop' : 'B',
    'White_Knight' : 'N',
    'White_Queen' : 'Q',
    'White_King' : 'K',
    'White_Pawn' : 'P',
    'Black_Rook' : 'r',
    'Black_Bishop' : 'b',
    'Black_Knight' : 'n',
    'Black_Queen' : 'q',
    'Black_King' : 'k',
    'Black_Pawn' : 'p',
}