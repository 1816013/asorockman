#pragma once

#define AST() {\
	CHAR ast_mes[256];\
	wsprintf(ast_mes, "%s %ds–Ú\0", __FILE__, __LINE__);\
	MessageBox(0, ast_mes, "±»°Ä•\¦", MB_OK);\
	}