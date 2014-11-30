.PHONY: clean All

All:
	@echo ----------Building project:[ fira - Debug ]----------
	@cd "fira" && "$(MAKE)" -f "fira.mk"
clean:
	@echo ----------Cleaning project:[ fira - Debug ]----------
	@cd "fira" && "$(MAKE)" -f "fira.mk" clean
