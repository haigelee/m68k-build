/*
 * cf-isv.c -- 
 *
 * Copyright (c) 2006 CodeSourcery Inc
 *
 * The authors hereby grant permission to use, copy, modify, distribute,
 * and license this software and its documentation for any purpose, provided
 * that existing copyright notices are retained in all copies and that this
 * notice is included verbatim in any distributions. No written agreement,
 * license, or royalty fee is required for any of the authorized uses.
 * Modifications to this software may be copyrighted by their authors
 * and need not follow the licensing terms described here, provided that
 * the new terms are clearly indicated on the first page of each file where
 * they apply.
 */

/* This file contains default interrupt handlers code for the
   interrupt vector.  All but one of the interrupts are user
   replaceable.

   These interrupt handlers are entered whenever the associated
   interrupt occurs.  All they do is stop the debugger to give the user
   the opportunity to determine where the problem was.  */


/* Each ISR is a loop containing a halt instruction  */
#define ISR_DEFINE(NAME) 					\
void __attribute__((interrupt_handler)) NAME (void)		\
{								\
  while (1)							\
    __asm__ __volatile__ ("halt" ::: "memory");			\
}								\
struct eat_trailing_semicolon

ISR_DEFINE (__other_interrupt);

ISR_DEFINE (__reset);

ISR_DEFINE (__access_error);

ISR_DEFINE (__address_error);

ISR_DEFINE (__illegal_instruction);

ISR_DEFINE (__divide_by_zero);

ISR_DEFINE (__privilege_violation);

ISR_DEFINE (__trace);

ISR_DEFINE (__unimplemented_line_a_opcode);

ISR_DEFINE (__unimplemented_line_f_opcode);

ISR_DEFINE (__non_pc_breakpoint_debug_interrupt);

ISR_DEFINE (__pc_breakpoint_debug_interrupt);

ISR_DEFINE (__format_error);

ISR_DEFINE (__spurious_interrupt);

ISR_DEFINE (__trap0);

ISR_DEFINE (__trap1);

ISR_DEFINE (__trap2);

ISR_DEFINE (__trap3);

ISR_DEFINE (__trap4);

ISR_DEFINE (__trap5);

ISR_DEFINE (__trap6);

ISR_DEFINE (__trap7);

ISR_DEFINE (__trap8);

ISR_DEFINE (__trap9);

ISR_DEFINE (__trap10);

ISR_DEFINE (__trap11);

ISR_DEFINE (__trap12);

ISR_DEFINE (__trap13);

ISR_DEFINE (__trap14);

ISR_DEFINE (__trap15);

ISR_DEFINE (__fp_branch_unordered);

ISR_DEFINE (__fp_inexact_result);

ISR_DEFINE (__fp_divide_by_zero);

ISR_DEFINE (__fp_underflow);

ISR_DEFINE (__fp_operand_error);

ISR_DEFINE (__fp_overflow);

ISR_DEFINE (__fp_input_not_a_number);

ISR_DEFINE (__fp_input_denormalized_number);

ISR_DEFINE (__unsupported_instruction);
