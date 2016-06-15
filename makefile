move_generate.o:generate_move.h generate_move.c chess.h is_valid_pos.h
	gcc -c -o generate.o generate_move.c
clean:
	rm generate.o
