CC = gcc
CFLAGS = -Wall -Wextra

SRC_DIR = src
OBJ_DIR = obj

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

TARGET = trek

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean install uninstall

install: $(TARGET)
	mkdir -p /usr/local/bin
	cp $(TARGET) /usr/local/bin/trek
	cp trek.sh /usr/local/bin/trek.sh
	chmod +x /usr/local/bin/trek.sh
	echo '' >> $(HOME)/.bashrc
	echo '# trek directory navigator' >> $(HOME)/.bashrc
	echo 'trek() { source /usr/local/bin/trek.sh; }' >> $(HOME)/.bashrc
	@echo "Done! Run 'source ~/.bashrc' to activate trek."

uninstall:
	rm -f /usr/local/bin/trek
	rm -f /usr/local/bin/trek.sh
	sed -i '/# trek directory navigator/d' $(HOME)/.bashrc
	sed -i '/trek() { source \/usr\/local\/bin\/trek.sh; }/d' $(HOME)/.bashrc
	@echo "Done! Run 'source ~/.bashrc' to apply changes."

clean:
	rm -rf $(OBJ_DIR) $(TARGET)