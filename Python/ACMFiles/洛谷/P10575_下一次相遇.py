from datetime import date, timedelta

# 起始日期：2024年6月1日
start_date = date(2024, 6, 1)
current_date = start_date
max_iterations = 100  # 防止无限循环的安全保护

iteration_count = 0
while iteration_count < max_iterations:
    # 使用replace方法准确计算下一年的同一天，避免闰年问题
    try:
        current_date = current_date.replace(year=current_date.year + 1)
    except ValueError:
        # 处理2月29日的特殊情况（虽然本题不涉及）
        current_date = current_date.replace(year=current_date.year + 1, day=28)
    
    # isoweekday(): 1=Monday, 6=Saturday, 7=Sunday
    if current_date.isoweekday() == 6:
        print(current_date.year)
        break
    
    iteration_count += 1
else:
    # 如果超过最大迭代次数仍未找到，输出警告
    print("未在预期范围内找到结果")
