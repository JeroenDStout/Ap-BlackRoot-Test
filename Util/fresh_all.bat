@echo off

echo.
echo --
echo -- Fresh Templates
echo --
echo.
python "Repo/fresh_templates.py"

echo.
echo --
echo -- Util Fix Submodules
echo --
echo.
python "Repo/util_fixsubmodules.py"

pause