#include "ft_printf/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int ft_ret, orig_ret;
    
    printf("=== DELIVERABLE FUNCTIONALITY TEST ===\n\n");
    
    // Test basic functionality
    ft_ret = ft_printf("ft_printf: %c %s %d %u %x %X %p %%\n", 'A', "test", -42, 42U, 255, 255, (void*)0x1234);
    orig_ret = printf("printf:    %c %s %d %u %x %X %p %%\n", 'A', "test", -42, 42U, 255, 255, (void*)0x1234);
    
    printf("Return values match: %s (ft=%d, printf=%d)\n", (ft_ret == orig_ret) ? "✅" : "❌", ft_ret, orig_ret);
    
    // Test edge cases
    ft_ret = ft_printf("Edge cases: %s %d\n", (char*)NULL, INT_MIN);
    orig_ret = printf("Edge cases: %s %d\n", (char*)NULL, INT_MIN);
    
    printf("Edge cases match: %s (ft=%d, printf=%d)\n", (ft_ret == orig_ret) ? "✅" : "❌", ft_ret, orig_ret);
    
    printf("\n✅ Deliverable test complete!\n");
    return (0);
}
