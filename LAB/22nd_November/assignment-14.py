# Take a suitable dataset of information about the applications opened by an user in his computer.
# Like
# Date       apps opened
# 20 nov     word, youtube, whatsapp, instagram
# 21 nov     youtube, whatsapp, instagram
# .....
# ....

# write the following functions.
# i) number of times the user opened whatsapp as his first time of the day. [20]
# ii) probability of opening whatsapp as his first choice. [20]
# iii) probability of opening whatsapp as his second choice if he has opened instagram as his first choice of that day.

import pandas as pd

# Get user input for custom data
num_entries = int(input("Enter the number of entries: "))
dates = []
apps_opened = []

for _ in range(num_entries):
    date = input("Enter date (e.g., 20 nov): ")
    apps = input("Enter apps opened (comma-separated): ")
    dates.append(date)
    apps_opened.append(apps)

# Creating a dataframe with user-provided data
df = pd.DataFrame({"Date": dates, "apps opened": apps_opened})

# Function to calculate the number of times WhatsApp was opened as the first app
def first_app_whatsapp_count():
    whatsapp_first_count = 0
    for apps in df["apps opened"]:
        if apps.split(",")[0].strip().lower() == "whatsapp":
            whatsapp_first_count += 1
    return whatsapp_first_count

# Function to calculate the probability of opening WhatsApp as the first app
def first_app_whatsapp_probability():
    total_days = len(df)
    whatsapp_first_count = first_app_whatsapp_count()
    return whatsapp_first_count / total_days

# Function to calculate the probability of opening WhatsApp as the second app if Instagram was opened first
def second_app_whatsapp_probability():
    instagram_first_count = 0
    whatsapp_second_count = 0
    for apps in df["apps opened"]:
        app_list = [app.strip().lower() for app in apps.split(",")]
        if app_list[0] == "instagram":
            instagram_first_count += 1
            if len(app_list) > 1 and app_list[1] == "whatsapp":
                whatsapp_second_count += 1
    if instagram_first_count == 0:
        return 0
    else:
        return whatsapp_second_count / instagram_first_count

# Calling the functions and printing the results
print()
print("Number of times WhatsApp was opened as the first app:", first_app_whatsapp_count())
print("Probability of opening WhatsApp as the first app:", first_app_whatsapp_probability())
print(
    "Probability of opening WhatsApp as the second app if Instagram was opened first:",
    second_app_whatsapp_probability(),
)
