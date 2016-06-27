search:gcc -o search search.o move_generate.o evaluation.o moved.o is_king_attack.o
move_generate.o:generate_move.h generate_move.c chess.h is_valid_pos.h,search.h
	gcc -c -o generate.o generate_move.c
evaluation.o:evaluation.h evaluation.c chess.h search.h is_valud_pos.h 
	gcc -c -o evaluation.o evaluation.c
moved.o:moved.h moved.c search.h chess.h
	gcc -c -o moved.o moved.c
is_king_attack.o:is_king_attack.h is_king_attack.c chess.h search.h
	gcc -c -o is_king_attack.o is_king_attack.c
search.o:search.h search.c generate_move.h evaluation.h moved.h
	gcc -c -o search.o search.c
clean:
	rm generate.o moved.o evaluation.o is_king_attack.o search.o
