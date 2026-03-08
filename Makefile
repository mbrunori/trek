CC = gcc
CFLAGS = -Wall -Wextra
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
TARGET = trek

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o: %.c
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
	rm -f $(OBJ) $(TARGET)