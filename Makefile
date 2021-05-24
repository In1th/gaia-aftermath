
CC := g++
CFLAGS := -c
LDFLAGS := -s -lm
LIB := libeq.a
LDLIBS := -Llib -leq
EQ := ./src/item.o ./src/stackable.o ./src/nonstackable.o ./src/eq.o

.PHONY: eq_src

main.x: main.o $(LIB)

$(LIB): $(EQ)
	ar cr ./lib/libeq.a $(EQ)
	rm ./src/*.o
	

%.x: %.o
	$(CC) $(LDFLAGS) -o $@ $< $(LDLIBS)
	rm $<

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ $<