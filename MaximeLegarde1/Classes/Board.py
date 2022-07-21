import pygame
from .Pieces import *
from .Constants import *

class NewBoard :
    def __init__(self, width, height, rows, cols, square, window) :
        self.width = width
        self.height = height
        self.rows = rows
        self.cols = cols
        self.square = square
        self.window = window
        self.board = []
        self.create_board()
    

    def create_board(self) :
        for row in range(self.rows)  :
            self.board.append([0 for i in range(self.cols)])
            for col in range(self.cols) :

                if row == 1 :
                    self.board[row][col]=Pawn(self.square, BLACK_PAWN, BLACK, col, row, "Pawn")

                if row == 6 :
                    self.board[row][col] = Pawn(self.square, WHITE_PAWN, WHITE, col, row, "Pawn")

                
            if row == 0 :
                self.board[row] = [
                    Rook(self.square, BLACK_ROOK, BLACK,   0, row, "Rook"),
                    Knight(self.square, BLACK_KNIGHT, BLACK, 1, row, "Knight"),
                    Bishop(self.square, BLACK_BISHOP, BLACK, 2, row, "Bishop"),
                    Queen(self.square, BLACK_QUEEN, BLACK, 3, row, "Queen"), 
                    King(self.square, BLACK_KING, BLACK, 4, row, "King"), 
                    Bishop(self.square, BLACK_BISHOP, BLACK, 5, row, "Bishop"), 
                    Knight(self.square, BLACK_KNIGHT, BLACK, 6, row, "Knight"), 
                    Rook(self.square, BLACK_ROOK, BLACK, 7, row, "Rook")]
                
                
            if row == 7 :
                self.board[row] = [
                    Rook(self.square, WHITE_ROOK, WHITE, 0, row, "Rook"),
                    Knight(self.square, WHITE_KNIGHT, WHITE, 1, row,"Knight"),
                    Bishop(self.square, WHITE_BISHOP, WHITE, 2, row, "Bishop"),
                    Queen(self.square, WHITE_QUEEN, WHITE, 3, row, "Queen"), 
                    King(self.square, WHITE_KING, WHITE, 4, row, "King"), 
                    Bishop(self.square, WHITE_BISHOP, WHITE, 5, row, "Bishop"), 
                    Knight(self.square, WHITE_KNIGHT, WHITE, 6, row, "Knight"), 
                    Rook(self.square, WHITE_ROOK, WHITE, 7, row, "Rook")
                    ]

    def get_piece(self, row, col) :
        return self.board[row][col]
    

    def move(self, piece, row, col) :
        self.board[piece.row][piece.col], self.board[row][col] = 0, piece
        piece.piece_move(row, col)

        if piece.type == "Pawn" or piece.type == "Rook":
            piece.first_move = False

        for row in range(len(self.board)) :
            for col in range(len(self.board[0])):
                piece = self.board[row][col]
                if piece != 0 :
                    if piece.type == "EnPassant" :
                        self.board[piece.row][piece.col] = 0
        

            
    def draw_board(self) :
        self.window.fill(BLACK)
        for row in range(self.rows) :
            for col in range(row%2,self.cols,2) :
                pygame.draw.rect(self.window, WHITE, (SQUARE*row,SQUARE*col,SQUARE,SQUARE))
    
    def draw_piece(self, piece, window) :
        piece.calc_pos()
        if piece != 0:
            if piece.type == "EnPassant" :
                return
        window.blit(piece.image,(piece.x+5,piece.y+5))
    
    def draw_pieces(self) :
        for row in range (self.rows) :
            for col in range(self.cols) :
                if self.board[row][col] != 0 :
                    self.draw_piece(self.board[row][col], self.window)
    
    def print_board(self) :
        print(self.board)
    
    



