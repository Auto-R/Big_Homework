#pragma once
#include"include.h"

struct dat* fdlast(struct dat* dae);

void datacopy(struct dat* temp1, struct dat* temp2);

int nametopo(struct dat* dae, char trg[20]);

void output(struct dat* dae, FILE* fp);

struct dat* input(FILE* fp);
