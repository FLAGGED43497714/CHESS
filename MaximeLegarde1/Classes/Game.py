import pygame

import chess
from Classes.Pieces import EnPassant
from .Board import NewBoard
from .Ai import *
from .Constants import *
from copy import deepcopy

class Game:
    def __init__(self, width, height, rows, cols, square, window):
        self.window = window
        self.board = NewBoard(width, height, rows, cols, square, window)
        self.square = square
        self.selected = None
        self.turn = WHITE
        self.valid_moves = []
        self.white_pieces_left=16
        self.black_pieces_left=16
        self.PGN = ''
        self.trace = 0
        self.Ai = AI(self.get_fen(), 1)
    
    def update_window(self):
        self.board.draw_board()
        self.board.draw_pieces()
        self.draw_available_moves()
        pygame.display.update()
    
    def reset(self) :
        self.board = NewBoard(self.board.width, self.board.height, self.board.rows, self.board.cols, self.board.square, self.board.window)
        self.selected = None
        self.black_pieces_left,self.white_pieces_left = 16, 16
        self.turn = WHITE
        self.valid_moves = []
    
    def change_turn(self) :
        if self.turn == WHITE :
            self.turn = BLACK
        else : 
            self.turn = WHITE
        
    def select(self, row, col) :
        if self.selected :
            
            move = self._move(row, col)

            if not move:
                self.selected = None
            

        piece = self.board.get_piece(row, col)
        if piece != 0 and self.turn == piece.color :
            self.selected = piece
            self.valid_moves = piece.get_available_moves(row, col, self.board.board)


    def _move(self, row, col) :
        piece = self.selected
        if self.turn == WHITE :
            self.trace += 1
        #implementing en-passant
        if piece.type == "Pawn" :
            if self.turn == WHITE :
                if (piece.row, piece.col) == (row + 2, col) and piece.first_move:
                    if (row, col) in self.valid_moves and self.simulate_move(piece, row, col) :
                        self.board.move(piece, row, col)
                        if self.turn == WHITE :
                            self.PGN += '{}.'.format(self.trace) + ' ' + piece.letter + LETTERS[col]+'{}'.format(8-row)
                        if self.turn == BLACK :
                            self.PGN += ' ' + piece.letter + LETTERS[col]+'{}'.format(8-row) + ' '
                        print(self.PGN)
                        piece.first_move = False
                        self.board.board[row + 1][col] = EnPassant(self.square, None, WHITE, col, row + 1, "EnPassant", piece)
                        self.valid_moves = []
                        self.selected = None
                        self.change_turn()
                        return True



            if self.turn == BLACK :
                if (piece.row, piece.col) == (row - 2, col) and piece.first_move:
                    if (row, col) in self.valid_moves and self.simulate_move(piece, row, col) :
                        self.board.move(piece, row, col)
                        piece.first_move = False
                        self.board.board[row - 1][col] = EnPassant(self.square, None, BLACK, col, row - 1, "EnPassant", piece)
                        if self.turn == WHITE :
                            self.PGN += '{}.'.format(self.trace) + ' ' + piece.letter + LETTERS[col]+'{}'.format(8-row)
                        if self.turn == BLACK :
                            self.PGN += ' ' + piece.letter + LETTERS[col]+'{}'.format(8-row) + ' '
                        print(self.PGN)
                        self.valid_moves = []
                        self.selected = None
                        self.change_turn()
                        return True
            
        #implement castling
        if piece.type == "King" :
            #long castle
            if (row, col) == (piece.row, piece.col - 2) and 'long_castle' in piece.available_moves :
                if self.simulate_move(self.selected, row, col + 1) and self.simulate_move(self.selected, row, col) :
                    self.board.move(piece, row, col)
                    piece.first_move = False
                    rook = self.board.board[row][col - 2]
                    self.board.move(rook, row, col + 1)
                    if self.turn == WHITE :
                            self.PGN += '{}.'.format(self.trace) + ' O-O-O' 
                    if self.turn == BLACK :
                        self.PGN += ' ' + piece.letter + 'O-O-O '
                    print(self.PGN)
                    self.valid_moves = []
                    self.selected = None
                    self.change_turn()
                    return True

            #short castle
            if (row, col) == (piece.row, piece.col + 2) and 'short_castle' in piece.available_moves :
                if self.simulate_move(self.selected, row , col - 1) and self.simulate_move(self.selected, row, col):
                    self.board.move(piece, row, col)
                    piece.first_move = False 
                    rook = self.board.board[row][col + 1]
                    self.board.move(rook, row, col - 1)
                    if self.turn == WHITE :
                        self.PGN += '{}.'.format(self.trace) + ' O-O'
                    if self.turn == BLACK :
                        self.PGN += ' O-O '
                    print(self.PGN)
                    self.valid_moves = []
                    self.selected = None
                    self.change_turn()
                    return True
    
        if self.selected and (row, col) in self.valid_moves :
            if self.simulate_move(self.selected, row, col) :
                if self.board.board[row][col] != 0 :
                    if self.board.board[row][col].type == "EnPassant" :
                        pawn = self.board.board[row][col].Pawn
                        self.remove(pawn, pawn.row, pawn.col)
                self.remove(self.selected, row, col) 
                self.board.move(piece, row, col)
                if self.turn == WHITE :
                    self.PGN += '{}.'.format(self.trace) + ' ' + piece.letter + LETTERS[col]+'{}'.format(8-row)
                if self.turn == BLACK :
                    self.PGN += ' ' + piece.letter + LETTERS[col]+'{}'.format(8-row) + ' '
                print(self.PGN)
                self.valid_moves = []
                self.selected = None
                self.change_turn()
                return True

        return False

    def remove(self, piece, row, col):
        if piece != 0 :
            self.board.board[row][col] = 0
            self.white_pieces_left -= 1*(piece.color==WHITE)
            self.black_pieces_left -= 1*(piece.color==BLACK)
    
    def draw_available_moves(self) :
        if len(self.valid_moves) > 0 :
            for pos in self.valid_moves :
                if pos == 'short_castle' :
                    pos = self.get_King_pos(self.board.board)
                    row, col = pos[0], pos[1]+2
                    pygame.draw.circle(self.window, (150, 150, 150), ( col*self.square + self.square//2, row*self.square + self.square//2), 20)
                    return 
                if pos == 'long_castle' :
                    pos = self.get_King_pos(self.board.board)
                    row, col = pos[0], pos[1]-2
                    pygame.draw.circle(self.window, (150, 150, 150), ( col*self.square + self.square//2, row*self.square + self.square//2), 20)
                    return
                row, col = pos[0], pos[1]
                pygame.draw.circle(self.window, (150, 150, 150), ( col*self.square + self.square//2, row*self.square + self.square//2), 20)

    def enemy_moves(self, piece, board):
        enemy_moves = []
        for r in range(len(board)):
            for c in range(len(board[r])):
                if board[r][c] != 0 :
                    if board[r][c].color != piece.color:

                        moves = board[r][c].get_available_moves(r, c, board)
                        for move in moves : 
                            enemy_moves.append(move)
        return enemy_moves


    def get_King_pos(self, board):
        for r in range(len(board)):
            for c in range(len(board[r])):
                if board[r][c] != 0 :
                    if board[r][c].type == "King" and self.turn == board[r][c].color :
                        return (r, c)


    def simulate_move(self, piece, row, col) :
        piece_row, piece_col = piece.row, piece.col
        save_piece = self.board.board[row][col]
        bool= True
        if self.board.board[row][col] != 0 :
            self.board.board[row][col] = 0
        
        self.board.board[piece.row][piece.col], self.board.board[row][col] = self.board.board[row][col], self.board.board[piece.row][piece.col]


        king_pos = self.get_King_pos(self.board.board) 

        if king_pos in self.enemy_moves(piece, self.board.board) :
            bool = False

        piece.row, piece.col= piece_row, piece_col
        self.board.board[piece_row][piece_col] = piece
        self.board.board[row][col] = save_piece

        return bool

    def possible_moves(self, board):
        possible_moves = []
        for r in range(len(board)) :
            for c in range(len(board[r])):
                if board[r][c] != 0:
                    if board[r][c].color == self.turn and board[r][c].type != "King" :
                        moves = board[r][c].get_available_moves(r, c, board) 
                        for move in moves :
                            possible_moves.append(move)
        return possible_moves


    def checkmate(self, board):
        king_pos = self.get_King_pos(board.board)
        get_king = board.get_piece(king_pos[0], king_pos[1])
        king_available_moves = set(get_king.get_available_moves(king_pos[0],king_pos[1], board.board))
        enemy_moves_set = set(self.enemy_moves(get_king, board.board))
        king_moves = king_available_moves - enemy_moves_set
        set1 = king_available_moves.intersection(enemy_moves_set)
        possible_moves_to_def = set1.intersection(self.possible_moves(board.board))

        if len(king_moves) == 0 and len(king_available_moves) != 0 and possible_moves_to_def == 0 :
            return True

        return False

    def check_game(self) :
        if self.checkmate(self.board) :
            if self.turn == WHITE :
                print("Black wins")
                return True
            else :
                print("White wins")
                return True
    
    def get_fen(self) :
        board = self.board.board
        fen = ''
        r , c = 0 , 0
        b = False
        for row in range(len(board)) :
            i = 0
            for col in range(len(board[0])) :
                piece = board[row][col]
                if piece != 0 :
                    if piece.type == 'EnPassant' :
                        b = True
                        r = 8-row
                        c = col
                        i+=1
                    else :
                        if piece.color == WHITE :
                            fen += '{}'.format(i)*(i != 0) + PIECES_FEN['White_' + piece.type]
                            i = 0
                        else :
                            fen += '{}'.format(i)*(i != 0) + PIECES_FEN['Black_' + piece.type]
                            i = 0
                else : 
                    i+=1
            fen += '{}'.format(i)*(i != 0) +"/"*(row != 7)

        #turn in FEN
        fen += ' w '*(self.turn == WHITE) + ' b '*(self.turn == BLACK)

        #castling in FEN
        white_short = False
        white_long = False
        if board[7][4] != 0:
            if board[7][4].type == 'King' :
                if board[7][4].first_move :
                    if board[7][7] != 0 :
                        if board[7][7].type == 'Rook' :
                            if board[7][7].first_move :
                                
                                white_short = True


                    if board[7][0] != 0 :
                        if board[7][0].type == 'Rook' :
                            if board[7][0].first_move :
                                
                                white_long = True

        if white_short :
            fen += 'K'
        

        if white_long :
            fen += 'Q'
    
        
        black_long = False
        black_short = False

        if board[0][4] != 0:
            if board[0][4].type == 'King' :
                if board[0][4].first_move :
                    if board[0][7] != 0 :
                        if board[0][7].type == 'Rook' :    
                            if board[0][7].first_move :
                                black_short = True
                    
                    if board[0][0] != 0 :
                        if board[0][0].type == 'Rook':
                            if board[0][0].first_move :
                                black_long = True
                
        if black_short :
            fen += 'k'
        if black_long :
            fen+='q'
        
        if not black_long and not black_short and not white_short and not white_long :
            fen += '-'
        

        #en passant FEN           
        if b :
            fen += ' '+ LETTERS[c] + '{} '.format(r)
        else : 
            fen += ' - '
        #rule of the 50 moves
        fen += '0 '
        #number of moves
        fen += '{}'.format(self.trace)


        return fen