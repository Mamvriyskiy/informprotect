CC := gcc
FLAGS := -std=c99 -Wall -Werror -Wextra -Wfloat-equal -Wfloat-conversion -pedantic
U_FLAGS := -lcheck -lpthread -lrt -lm -lsubunit
FUNC_VLG :=

SRC_DIR := ./src
INC_DIR := ./inc
OBJ_DIR := ./out

SRC := $(wildcard $(SRC_DIR)/*.c)
INC := $(wildcard $(INC_DIR)/*.h)

OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
OBJ_UNIT := $(patsubst $(UNIT_DIR)/%.c, $(OBJ_DIR)/%.o, $(UNITS))
OBJ_UNIT += $(filter-out $(OBJ_DIR)/main.o, $(OBJ))
INC_HD := -I$(INC_DIR)

APP = app.exe

$(APP) : $(OBJ)
	$(CC) $(OBJ) -o $@

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INC) $(OBJ_DIR)
	$(CC) $(INC_HD) $(FLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(UNIT_DIR)/%.c $(INC) $(OBJ_DIR)
	$(CC) $(INC_HD) $(FLAGS) $(U_FLAGS) -c $< -o $@

.PHONY : clean debug

debug : $(APP)
debug : FLAGS += -g3


clean:
	rm -rf $(OBJ_DIR) *.exe *.txt ./func_tests/*.txt *./out *.out;
