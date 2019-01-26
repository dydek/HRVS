#include "State.h"

volatile struct CurrentValues current_values;

void update_chr_variables()
{
    formatTemperature(current_values.in_temp_pre, (char *)current_values.in_temp_pre_chr);
    formatTemperature(current_values.in_temp_post, (char *)current_values.in_temp_post_chr);
    formatTemperature(current_values.out_temp_pre, (char *)current_values.out_temp_pre_chr);
    formatTemperature(current_values.out_temp_post, (char *)current_values.out_temp_post_chr);
};