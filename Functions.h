#pragma once
#ifndef PROJECT2_FUNCTIONS_H
#define PROJECT2_FUNCTIONS_H

void DisplayMenu();
void DisplayMenuInput(double& t_initInv, double& t_monthlyDep, double& t_annualInt, int& t_numYears);
void DisplayNoDeposit(double t_initInv, double t_annualInt, int t_numYears);
void DisplayDeposit(double t_initInv, double t_monthlyDep, double t_annualInt, int t_numYears);
void YearBalNoDeposit(double t_initInv, double t_annualInt, int t_numYears);
void YearBalDeposit(double t_initInv, double t_monthlyDep, double t_annualInt, int t_numYears);

#endif