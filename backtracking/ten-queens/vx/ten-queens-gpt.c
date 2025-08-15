/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ten-queens_gpt_ver.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:49:21 by jegerman          #+#    #+#             */
/*   Updated: 2025/08/15 17:49:28 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>

#define N 10

static void print_solution(uint16_t cols_mask_seq[], int depth) {
    char out[N+1]; out[N] = '\n';
    for (int c = 0; c < N; ++c) {
        // recover row index from single-bit mask
        uint16_t bit = cols_mask_seq[c];
        int row = 0;
        while ((bit >> row) != 1) ++row;
        out[c] = '0' + row;
    }
    write(1, out, N+1);
}

static void solve_bitmask(int col,
                          uint16_t cols_forbid,   // rows already taken
                          uint16_t diag1_forbid,  // '\' diag (shifts left)
                          uint16_t diag2_forbid,  // '/'  diag (shifts right)
                          uint16_t choice_seq[],  // store chosen row-bits per col
                          int *count)
{
    if (col == N) {
        print_solution(choice_seq, N);
        ++*count;
        return;
    }
    // all rows available in this column:
    uint16_t allowed = ~(cols_forbid | diag1_forbid | diag2_forbid) & ((1u<<N)-1);

    while (allowed) {
        uint16_t pick = allowed & -allowed;     // lowest set bit
        allowed ^= pick;                         // remove it

        choice_seq[col] = pick;

        // place queen at row r for this column
        // next column’s forbidden masks:
        solve_bitmask(col + 1,
                      cols_forbid | pick,
                      (uint16_t)((diag1_forbid | pick) << 1),
                      (uint16_t)((diag2_forbid | pick) >> 1),
                      choice_seq,
                      count);
    }
}

int ft_ten_queens_puzzle(void) {
    int count = 0;
    uint16_t seq[N] = {0};
    solve_bitmask(0, 0, 0, 0, seq, &count);
    return count; // should be 724
}
