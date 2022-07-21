from .Constants import *

class Piece :

    def __init__(self, square, image, color, col, row, type) :

        self.square = square
        self.image = image
        self.color = color
        self.col = col
        self.row = row
        self.type = type
        self.x = 0
        self.y = 0
        self.available_moves=[]

    def piece_move(self, row, col) :
        self.row = row
        self.col = col
        self.calc_pos()


    def calc_pos(self) :
        self.x = self.col*self.square
        self.y = self.row*self.square 

    def clear_available_moves(self) :
        if len(self.available_moves)>0 :
            self.available_moves=[]


class Pawn(Piece) :
    def __init__(self, square, image, color, col, row, type):
        super().__init__(square, image, color, col, row, type)
        self.first_move = True
        self.letter = ''
        
    def get_available_moves(self, row, col, Board) :

        self.clear_available_moves()

        #Check white pawn moves
        if self.color == WHITE :
            if row - 1 >= 0 :
                if Board[row - 1][col] == 0 :
                    self.available_moves.append((row - 1,col))
                    

                    if self.first_move :
                        if Board[row-2][col] == 0 :
                            self.available_moves.append((row - 2,col))

                #Check the captures for the white pawn
                if col - 1 >= 0 :
                    if Board[row - 1][col - 1] != 0 :
                        piece = Board[row - 1][col - 1]
                        if piece.color != self.color :
                            self.available_moves.append((row - 1, col - 1))

                if col + 1 < len(Board[0]) :
                    if Board[row - 1][col + 1] !=0 :
                        piece = Board[row - 1][col + 1]
                        if piece.color != self.color :
                            self.available_moves.append((row - 1, col + 1))


        #Check black pawn moves
        if self.color == BLACK :
            if row + 1 < len(Board) :
                if Board[row + 1][col] == 0 :
                    self.available_moves.append((row + 1, col))


                    if self.first_move :
                        if Board[row+2][col] == 0 :
                            self.available_moves.append((row + 2, col))

                #Check the captures for the black pawn
                if col - 1 >= 0 :
                    if Board[row + 1][col - 1] !=0 :
                        piece = Board[row + 1][col - 1]
                        if piece.color != self.color :
                            self.available_moves.append((row + 1, col - 1))

                if col + 1 < len(Board[0]) :
                    if Board[row + 1][col + 1] !=0 :
                        piece = Board[row + 1][col + 1]
                        if piece.color != self.color :
                            self.available_moves.append((row + 1, col + 1))


        return self.available_moves

class Rook(Piece) :

    def __init__(self, square, image, color, col, row, type) :
        super().__init__(square, image, color, col, row, type)
        self.first_move = True
        self.letter = 'R'

    def get_available_moves(self, row, col, Board) :
        self.clear_available_moves()
        

        #Check horizontal positive moves
        for i in range(row + 1, len(Board)) :
            if Board[i][col] == 0 :
                 self.available_moves.append((i, col))
            else : 
                if self.color != Board[i][col].color :
                    self.available_moves.append((i, col))
                break
        #Check vertical positive moves
        for j in range(col + 1,  len(Board[0])) :
            if Board[row][j] == 0 :
                self.available_moves.append((row,j))
            else :
                if self.color != Board[row][j].color :
                    self.available_moves.append((row, j))
                break
        #Check horizontal negative moves
        for i in range(row - 1, -1,-1) :
            if Board[i][col] == 0 :
                 self.available_moves.append((i, col))
            else : 
                if self.color != Board[i][col].color :
                    self.available_moves.append((i, col))
                break
        #Check vertical negative moves
        for i in range(col - 1 , -1, -1) :
            if Board[row][i] == 0 :
                 self.available_moves.append((row, i))
            else : 
                if self.color != Board[row][i].color :
                    self.available_moves.append((row, i))
                break
        
        return self.available_moves

class Bishop(Piece):
    def  __init__(self, square, image, color, col, row, type):
        super().__init__(square, image, color, col, row, type)
        self.letter = 'B'
    def get_available_moves(self, row, col, Board) :
        self.clear_available_moves()

        #Checking the first diagonal
        i=0
        while col + i + 1 < len(Board[0]) and row + i + 1 < len(Board) :
            piece = Board[row + i + 1][col + i + 1]
            i+=1
            if  piece == 0 :
                self.available_moves.append((row + i , col + i ))
            else :
                if piece.color != self.color :
                    self.available_moves.append((row + i, col + i))
                break
        
        #Checking second diagonal
        i=0
        while col - i - 1 >=0 and row + i + 1 < len(Board) :
            piece = Board[row + i + 1][col - i - 1]
            i+=1
            if  piece == 0 :
                self.available_moves.append((row + i , col - i ))
            else :
                if piece.color != self.color :
                    self.available_moves.append((row + i, col - i))
                break    
        
        #Checking third diagonal
        i=0
        while col + i + 1 < len(Board[0]) and row - i - 1 >= 0  :
            piece = Board[row - i - 1][col + i + 1]
            i+=1
            if  piece == 0 :
                self.available_moves.append((row - i , col + i ))
            else :
                if piece.color != self.color :
                    self.available_moves.append((row - i, col + i))  
                break

        #Checking the fourth diagonal
        i=0
        while col - i - 1 >= 0 and row - 1 - i >= 0 :
            piece = Board[row - i - 1][col - i - 1]
            i+=1
            if  piece == 0 :
                self.available_moves.append((row - i , col - i ))
            else :
                if piece.color != self.color :
                    self.available_moves.append((row - i, col - i))
                break
        
        return self.available_moves



class Knight(Piece) :
    def __init__(self, square, image, color, col, row, type):
        super().__init__(square, image, color, col, row, type)
        self.letter = 'N'

    def get_available_moves(self, row, col, Board):

        self.clear_available_moves()
        #first two squares
        if col + 2 < len(Board[0]) :
            if row + 1 < len(Board) :
                if Board[row + 1][col + 2] == 0 :
                    self.available_moves.append((row + 1, col + 2))
                else :
                    if Board[row + 1][col + 2].color != self.color :
                        self.available_moves.append((row + 1, col + 2))
            if row - 1 >=0 :
                if Board[row - 1][col + 2] == 0 :
                    self.available_moves.append((row - 1, col + 2))
                else:
                    if Board[row - 1][col + 2].color != self.color :
                        self.available_moves.append((row - 1, col + 2))
        
        #second two squares
        if col - 2 >= 0 :
            if row + 1 < len(Board) :
                if Board[row + 1][col - 2] == 0 :
                    self.available_moves.append((row + 1, col - 2))
                else :
                    if Board[row + 1][col - 2].color != self.color :
                        self.available_moves.append((row + 1, col - 2))
            if row - 1 >=0 :
                if Board[row - 1][col - 2] == 0 :
                    self.available_moves.append((row - 1, col - 2))
                else:
                    if Board[row - 1][col - 2].color != self.color :
                        self.available_moves.append((row - 1, col - 2))


        #third two squares
        if row + 2 < len(Board) :
            if col + 1 < len(Board[0]) :
                if Board[row + 2][col + 1] == 0 :
                    self.available_moves.append((row + 2, col + 1))
                else:
                    if Board[row + 2][col + 1].color != self.color :
                        self.available_moves.append((row + 2, col + 1))
            if col - 1 >= 0 :
                if Board[row + 2][col - 1] == 0 :
                    self.available_moves.append((row + 2, col - 1))
                else:
                    if Board[row + 2][col - 1].color != self.color :
                        self.available_moves.append((row + 2, col - 1))


        #fourth square
        if row - 2 >= 0 :
            if col + 1 < len(Board[0]) :
                if Board[row - 2][col + 1] == 0 :
                    self.available_moves.append((row - 2, col + 1))
                else:
                    if Board[row - 2][col + 1].color != self.color :
                        self.available_moves.append((row - 2, col + 1))
            if col - 1 >= 0 :
                if Board[row - 2][col - 1] == 0 :
                    self.available_moves.append((row - 2, col - 1))
                else:
                    if Board[row - 2][col - 1].color != self.color :
                        self.available_moves.append((row - 2, col - 1))


        return self.available_moves






class Queen(Piece):
    def __init__(self, square, image, color, col, row, type):
        super().__init__(square, image, color, col, row, type)
        self.letter = 'Q'
    
    def get_available_moves(self, row, col, Board):
        self.clear_available_moves()
        #Checking the first diagonal
        i=0
        while col + i + 1 < len(Board[0]) and row + i + 1 < len(Board) :
            piece = Board[row + i + 1][col + i + 1]
            i+=1
            if  piece == 0 :
                self.available_moves.append((row + i , col + i ))
            else :
                if piece.color != self.color :
                    self.available_moves.append((row + i, col + i))
                break
        
        #Checking second diagonal
        i=0
        while col - i - 1 >=0 and row + i + 1 < len(Board) :
            piece = Board[row + i + 1][col - i - 1]
            i+=1
            if  piece == 0 :
                self.available_moves.append((row + i , col - i ))
            else :
                if piece.color != self.color :
                    self.available_moves.append((row + i, col - i))
                break    
        
        #Checking third diagonal
        i=0
        while col + i + 1 < len(Board[0]) and row - i - 1 >= 0  :
            piece = Board[row - i - 1][col + i + 1]
            i+=1
            if  piece == 0 :
                self.available_moves.append((row - i , col + i ))
            else :
                if piece.color != self.color :
                    self.available_moves.append((row - i, col + i))  
                break

        #Checking the fourth diagonal
        i=0
        while col - i - 1 >= 0 and row - 1 - i >= 0 :
            piece = Board[row - i - 1][col - i - 1]
            i+=1
            if  piece == 0 :
                self.available_moves.append((row - i , col - i ))
            else :
                if piece.color != self.color :
                    self.available_moves.append((row - i, col - i))
                break
        
        #Check horizontal positive moves
        for i in range(row + 1, len(Board)) :
            if Board[i][col] == 0 :
                 self.available_moves.append((i, col))
            else : 
                if self.color != Board[i][col].color :
                    self.available_moves.append((i, col))
                break
        #Check vertical positive moves
        for j in range(col + 1,  len(Board[0])) :
            if Board[row][j] == 0 :
                self.available_moves.append((row,j))
            else :
                if self.color != Board[row][j].color :
                    self.available_moves.append((row, j))
                break
        #Check horizontal negative moves
        for i in range(row - 1, -1,-1) :
            if Board[i][col] == 0 :
                 self.available_moves.append((i, col))
            else : 
                if self.color != Board[i][col].color :
                    self.available_moves.append((i, col))
                break
        #Check vertical negative moves
        for i in range(col - 1 , -1, -1) :
            if Board[i][col] == 0 :
                 self.available_moves.append((row, i))
            else : 
                if self.color != Board[i][col].color :
                    self.available_moves.append((row, i))
                break

        return self.available_moves




class King(Piece):
    def __init__(self, square, image, color, col, row, type):
        super().__init__(square, image, color, col, row, type)
        self.first_move = True
        self.is_check = False
        self.letter = 'K'
    
    def get_available_moves(self, row, col, Board):
        self.clear_available_moves()

        if row - 1 >= 0 :
            if Board[row - 1][col] == 0 or Board[row - 1][col].color != self.color :
                self.available_moves.append((row - 1, col))
            if col - 1 >= 0 :
                if Board[row - 1][col - 1] == 0 or Board[row - 1][col - 1].color != self.color :
                    self.available_moves.append((row - 1, col - 1))

            if col + 1 <len(Board[0]) :
                if Board[row - 1][col + 1] == 0 or Board[row - 1][col + 1].color != self.color :
                    self.available_moves.append((row - 1, col + 1))

        if row + 1 < len(Board) :
            if Board[row + 1][col] == 0 or Board[row + 1][col].color != self.color :
                self.available_moves.append((row + 1, col))

            if col - 1 >= 0 :
                if Board[row + 1][col - 1] == 0 or Board[row + 1][col - 1].color != self.color :
                    self.available_moves.append((row + 1, col - 1))

            if col + 1 <len(Board[0]) :
                if Board[row + 1][col + 1] == 0 or Board[row + 1][col + 1].color != self.color :
                    self.available_moves.append((row + 1, col + 1))
        
        if col - 1 >= 0 :
            if Board[row][col - 1] == 0 or Board[row][col - 1].color != self.color :
                self.available_moves.append((row, col - 1))
        if col + 1 < len(Board[0]) :
            if Board[row][col + 1] == 0 or Board[row][col + 1].color != self.color :
                self.available_moves.append((row, col + 1))

        if self.first_move :

            if self.color == WHITE :
                if Board[7][7] != 0 :
                    if not self.is_check and Board[7][6] == 0 and Board[7][5] == 0 and Board[7][7].type == "Rook" and Board[7][7].first_move == True:
                        self.available_moves.append('short_castle')
                if Board[7][0] != 0 :
                    if not self.is_check and Board[7][3] == 0 and Board[7][2] == 0 and Board[7][1] == 0 and Board[7][0].type == "Rook" and Board[7][0].first_move == True:
                        self.available_moves.append('long_castle')

            if self.color == BLACK :
                if Board[0][7] != 0 :
                    if  Board[0][6] == 0 and Board[0][5] == 0 and Board[0][7].type == "Rook" :
                        if Board[0][7].first_move == True:
                            self.available_moves.append('short_castle')
                if Board[0][0] != 0 :
                    if Board[0][3] == 0 and Board[0][2] == 0 and Board[0][1] == 0 and Board[0][0].type == "Rook" :
                        if Board[7][0].first_move == True:
                            self.available_moves.append('long_castle')
        
        return self.available_moves



class EnPassant(Piece):
    def __init__(self, square, image, color, col, row, type, Pawn):
        super().__init__(square, image, color, col, row, type)
        self.Pawn = Pawn
    def get_available_moves(self, row, col, Board):
        return self.available_moves