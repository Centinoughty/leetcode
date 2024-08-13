# Display the first three rows
# EASY

import pandas as pd

def selectFirstRows(employees: pd.DataFrame) -> pd.DataFrame:
  return employees.head(3)