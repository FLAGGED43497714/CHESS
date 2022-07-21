import chess
import numpy
import tensorflow as tf
from .Constants import *

class AI :

    def __init__(self, fen, depth):

        self.model = tf.keras.models.load_model('Classes\model.h5')
        self.board = chess.Board(fen)
        self.depth = depth


    # example: h3 -> 17
    def square_to_index(self, square):
        letter = chess.square_name(square)
        return 8 - int(letter[1]), SQUARES_INDEX[letter[0]]


    def split_dims(self):
    # this is the 3d matrix
        board3d = numpy.zeros((14, 8, 8), dtype=numpy.int8)

    # here we add the pieces's view on the matrix
        for piece in chess.PIECE_TYPES:
            for square in self.board.pieces(piece, chess.WHITE):
                idx = numpy.unravel_index(square, (8, 8))
                board3d[piece - 1][7 - idx[0]][idx[1]] = 1
            for square in self.board.pieces(piece, chess.BLACK):
                idx = numpy.unravel_index(square, (8, 8))
                board3d[piece + 5][7 - idx[0]][idx[1]] = 1  

        # add attacks and valid moves too
        # so the network knows what is being attacked
        aux = self.board.turn
        self.board.turn = chess.WHITE
        for move in self.board.legal_moves:
            i, j = self.square_to_index(move.to_square)
            board3d[12][i][j] = 1
        self.board.turn = chess.BLACK
        for move in self.board.legal_moves:
            i, j = self.square_to_index(move.to_square)
            board3d[13][i][j] = 1
        self.board.turn = aux
        return board3d

    # used for the minimax algorithm
    def minimax_eval(self):
        board3d = self.split_dims()
        board3d = numpy.expand_dims(board3d, 0)
        eval = self.model.predict(board3d)[0][0]
        return eval


    def minimax(self, depth, alpha, beta, maximizing_player):
        if depth == 0 or self.board.is_game_over():
            return self.minimax_eval()
    
        if maximizing_player:
            max_eval = -numpy.inf
            for move in self.board.legal_moves:
                self.board.push(move)
                eval = self.minimax( depth - 1, alpha, beta, False)
                self.board.pop()
                max_eval = max(max_eval, eval)
                alpha = max(alpha, eval)
                if beta <= alpha:
                    break
            return max_eval
        else:
            min_eval = numpy.inf
            for move in self.board.legal_moves:
                self.board.push(move)
                eval = self.minimax(depth - 1, alpha, beta, True)
                self.board.pop()
                min_eval = min(min_eval, eval)
                beta = min(beta, eval)
                if beta <= alpha:
                    break
            return min_eval


    # this is the actual function that gets the move from the neural network
    def get_ai_move(self):
        max_move = None
        max_eval = numpy.inf
        for move in self.board.legal_moves:
            self.board.push(move)
            eval = self.minimax(self.depth - 1, -numpy.inf, numpy.inf, False)
            self.board.pop()
            if eval < max_eval:
                max_eval = eval
                max_move = move
        print(max_eval)
        return max_move

    def update_board(self,fen) :
        self.board = chess.Board(fen)