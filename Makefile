server:
	@echo "Launching server"
	make -C ./server/ run

client:
	@echo "Unimplemented"

.PHONY: server client