C_COMPILER=gcc
CFLAGS = -Wall -g

# Directories
ROOT = ../../

SRC_FILES=\
  $(wildcard ./*.c) \
  $(ROOT)utility/utility.c

INC_DIRS=\
  -I$(ROOT)utility                \
  -I$(ROOT)linkedList/generic     \

LIBS=\
  -lm

OUTPUT_FILE=main

.PHONY: clean
.PHONY: test

test:
	$(C_COMPILER) $(SRC_FILES) -o $(OUTPUT_FILE) $(CFLAGS) $(INC_DIRS)  $(LIBS) 
	./$(OUTPUT_FILE) -v

clean:
	rm -rf $(OUTPUT_FILE)
