C_COMPILER=gcc
CFLAGS = -Wall -g

# Directories
ROOT = ../../

SRC_FILES=\
  $(wildcard ./*.c) \
  $(ROOT)utility/utility.c

INC_DIRS=\
  -I$(ROOT)utility/

LIBS=\
  -lm

OUTPUT_FILE=main

.PHONY: clean
.PHONY: test

# Linear Hashing
linear:
	$(C_COMPILER) $(SRC_FILES) -o $(OUTPUT_FILE) $(CFLAGS) -DLINEARH $(INC_DIRS) $(LIBS) 
	./$(OUTPUT_FILE) -v

# Quadratic Hashing
quad:
	$(C_COMPILER) $(SRC_FILES) -o $(OUTPUT_FILE) $(CFLAGS) -DQUADH $(INC_DIRS) $(LIBS) 
	./$(OUTPUT_FILE) -v

# Double Hashing
double:
	$(C_COMPILER) $(SRC_FILES) -o $(OUTPUT_FILE) $(CFLAGS) -DDH $(INC_DIRS) $(LIBS) 
	./$(OUTPUT_FILE) -v

clean:
	rm -rf $(OUTPUT_FILE)
