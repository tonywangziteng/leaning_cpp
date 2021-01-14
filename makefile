top=$(CURDIR)
SRC_DIR=$(top)/utils
BUILD_DIR=$(SRC_DIR)
src = $(wildcard $(SRC_DIR)/*.cpp)  
obj = $(patsubst $(SRC_DIR)/%.cpp, %.o, $(src))  
#obj = $(src:%.c=%.o)  
target = test  
CC = g++

$(target): $(obj)
	@echo $(src)
	$(CC) $(obj) -o $(target)  

$(obg): $(src) 
	$(CC) -c $< -o $@  

.PHONY: clean  
clean:  
	rm -rf $(obj) $(target) 