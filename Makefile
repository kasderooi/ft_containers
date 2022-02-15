all:	catch_test speed_test subject_test

catch_test:
	@cd catch2 && make run;

speed_test:
	@cd timetest && make run;

subject_test:
	@cd subject && make run;

clean:
	@cd catch2 && make clean;
	@cd timetest && make clean;
	@cd subject && make clean;

fclean:
	@cd catch2 && make fclean;
	@cd timetest && make fclean;
	@cd subject && make fclean;

re:			fclean all

.PHONY:	all catch_test speed_test subject_test clean fclean re
