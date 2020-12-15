DO # prompt for user's name 
{
    $User = Read-Host -Prompt 'Input your name'
} 
WHILE ($user -eq "") # until something is input

$DateInfo = Get-Date -UFormat "It is %R on %A, %B%e, %Y.  UTC offset is %Z hours. Seconds in epoch is %s"

Clear-Host
Write-Host "`nHello, $User. Your user name on $env:computername is $env:USERNAME" 
Write-Host "$DateInfo"
Write-Host "The current directory : $(Get-Location)"
Write-Host "PS script full path is: $PSCommandPath"
Write-Host "`nEnviroment variables `$env:" -NoNewline
Write-Host "Name" -ForegroundColor DarkBlue -BackgroundColor White -NoNewline
Get-ChildItem Env: