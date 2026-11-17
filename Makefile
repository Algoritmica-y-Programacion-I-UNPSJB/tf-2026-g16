TARGET = ahorcado
OBJS = main.o ui_ranking.o ui_inicio.o ui_palabras.o ui_partida.o 
CFLAGS = -Wall

$(TARGET) : $(OBJS)
	gcc $(CFLAGS) $(OBJS) -o $(TARGET)

%.o : %.c
	gcc -c $(CFLAGS) $< -o $@

.PHONY : clean
clean:
	@rm -f *.o $(TARGET)
