@echo off
chcp 65001 >nul
setlocal enabledelayedexpansion

echo ========================================
echo       开始执行文件夹拷贝操作
echo ========================================

REM 获取当前脚本所在目录作为根目录
set "ROOT_DIR=%~dp0"
echo 根目录: %ROOT_DIR%

REM 定义源目录和目标目录
set "SOURCE_1=Proj_Config\Bsw_Config\Gen"
set "TARGET_1=Proj_Code\_01_BSW\Gen"

set "SOURCE_2=Proj_Config\Mcal_Config\Gen"
set "TARGET_2=Proj_Code\_03_MCAL\Gen"

set "ERROR_FLAG=0"

echo.
echo 操作1: 拷贝 %SOURCE_1% 到 %TARGET_1%

REM 检查源目录是否存在
if not exist "%ROOT_DIR%%SOURCE_1%" (
    echo ✗ 错误: 源目录不存在 - %ROOT_DIR%%SOURCE_1%
    set "ERROR_FLAG=1"
    goto :CHECK_ERRORS
)

echo ✓ 源目录存在: %ROOT_DIR%%SOURCE_1%

REM 检查目标目录是否存在
if not exist "%ROOT_DIR%%TARGET_1%" (
    echo ✗ 错误: 目标目录不存在 - %ROOT_DIR%%TARGET_1%
    echo   请手动创建目标目录或检查路径是否正确
    set "ERROR_FLAG=1"
    goto :CHECK_ERRORS
)

echo ✓ 目标目录存在: %ROOT_DIR%%TARGET_1%

REM 执行拷贝操作，排除指定的文件
echo 正在拷贝文件（排除 vLinkGen_Template.lsl）...

REM 使用 robocopy 命令实现排除特定文件
robocopy "%ROOT_DIR%%SOURCE_1%" "%ROOT_DIR%%TARGET_1%" /E /XF "vLinkGen_Template.lsl" /NJH /NJS /NP /NDL

REM 检查 robocopy 执行结果（8及以上表示有错误或异常）
if errorlevel 8 (
    echo ✗ 错误: 拷贝操作失败（错误代码 %errorlevel%）
    set "ERROR_FLAG=1"
) else (
    echo ✓ 操作1完成
    echo   （已排除 vLinkGen_Template.lsl 文件）
)

:CHECK_ERRORS
if %ERROR_FLAG%==1 (
    echo.
    echo ❌ 操作1因错误中止
    goto :END_SCRIPT
)

echo.
echo 操作2: 拷贝 %SOURCE_2% 到 %TARGET_2%

REM 检查源目录是否存在
if not exist "%ROOT_DIR%%SOURCE_2%" (
    echo ✗ 错误: 源目录不存在 - %ROOT_DIR%%SOURCE_2%
    set "ERROR_FLAG=2"
    goto :CHECK_ERRORS_2
)

echo ✓ 源目录存在: %ROOT_DIR%%SOURCE_2%

REM 检查目标目录是否存在
if not exist "%ROOT_DIR%%TARGET_2%" (
    echo ✗ 错误: 目标目录不存在 - %ROOT_DIR%%TARGET_2%
    echo   请手动创建目标目录或检查路径是否正确
    set "ERROR_FLAG=2"
    goto :CHECK_ERRORS_2
)

echo ✓ 目标目录存在: %ROOT_DIR%%TARGET_2%

REM 执行拷贝操作
echo 正在拷贝文件...
xcopy "%ROOT_DIR%%SOURCE_2%\*" "%ROOT_DIR%%TARGET_2%\" /E /Y /I >nul
if errorlevel 1 (
    echo ✗ 错误: 拷贝操作失败
    set "ERROR_FLAG=2"
) else (
    echo ✓ 操作2完成
)

:CHECK_ERRORS_2
if %ERROR_FLAG%==2 (
    echo.
    echo ❌ 操作2因错误中止
)

:END_SCRIPT
echo.
echo ========================================
if %ERROR_FLAG%==0 (
    echo       ✅ 所有操作成功完成
) else (
    echo       ❌ 脚本执行过程中出现错误
    echo       错误代码: %ERROR_FLAG%
)
echo ========================================
echo.
echo 按任意键退出...
pause >nul
exit /b %ERROR_FLAG%