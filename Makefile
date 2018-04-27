CODE_DIR = src
all:
	+$(MAKE) -C $(CODE_DIR)
clean: 
	$(MAKE) -C $(CODE_DIR) clean 
