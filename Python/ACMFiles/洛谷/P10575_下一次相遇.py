from datetime import date, timedelta

# 从2024年6月1日开始，逐年查找下一个6月1日是星期一的年份
current_date = date(2024, 6, 1)
one_year_delta = timedelta(days=365)

while True:
    current_date += one_year_delta
    # 检查当前日期的星期几（isoweekday()返回1表示星期一）
    if current_date.isoweekday() == 1:
        print(current_date.year)
        break
