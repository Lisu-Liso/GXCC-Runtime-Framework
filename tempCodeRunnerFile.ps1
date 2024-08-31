$owner = "Lisu-Liso"
$repo = "GXCC"
$url = "https://api.github.com/repos/$owner/$repo/releases/latest"
$response = Invoke-RestMethod -Uri $url -Headers @{ "User-Agent" = "PowerShell" }
$latestVersion = $response.tag_name
Write-Output $latestVersion >> .\test.json