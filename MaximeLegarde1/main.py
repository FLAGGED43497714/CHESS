from Classes.Constants import *
from Classes.Game import Game


pygame.init()

clock = pygame.time.Clock()

window = pygame.display.set_mode((WIDTH, HEIGHT))

def get_position(x, y) :

    row = y // SQUARE
    col = x // SQUARE
    
    return int(row), int(col)





def main(window) :

    game_over=False
    run =True
    game = Game(WIDTH, HEIGHT, ROWS, COLUMNS, SQUARE, window)

    while run :
        if game.check_game() : 
            game_over = True
            game.PGN += '#'

        if game.Ai.board.is_checkmate() :
                print('You Won !')
                game_over = True
                game.reset()
        
        if game.turn == BLACK :
            fen = game.get_fen()
            game.Ai.update_board(fen)
            
            move = game.Ai.get_ai_move()
            f = move.from_square
            print(move)
            
            t = move.to_square

            print(7-f//8,f%8)
            print(7-t//8,t%8)

            game.select(7-f//8,f%8)
            game.select(7-t//8,t%8)

            
        
        clock.tick(FPS)

        game.update_window()
        
        # Draws the surface object to the screen.  
        pygame.display.update()

        for event in pygame.event.get() :
        
                # if event object type is QUIT
                # then quitting the pygame
                # and program both.
                if event.type == pygame.QUIT :

                    run=False
                    # deactivates the pygame library
                    pygame.quit()
        
                    # quit the program.
                    quit()

                if event.type == pygame.KEYDOWN and game_over :
                    if event.type == pygame.K_SPACE :
                        game.reset()
                        
                
                if event.type == pygame.MOUSEBUTTONDOWN and not game_over :
                    if pygame.mouse.get_pressed()[0] :
                        location = pygame.mouse.get_pos()
                        row,col=get_position(location[0],location[1])
                        game.select(row, col)

main(window)
        

