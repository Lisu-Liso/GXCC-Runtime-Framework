# 替换以下变量为实际的仓库信息
$owner = "Lisu-Liso"
$repo = "GXCC"

# 构建 GitHub API 请求 URL
$url = "https://api.github.com/repos/$owner/$repo/releases/latest"

# 发起 HTTP 请求并获取 JSON 响应
$response = Invoke-RestMethod -Uri $url -Headers @{ "User-Agent" = "PowerShell" }

# 提取并输出最新 release 的版本号
$latestVersion = $response.tag_name
Write-Output $latestVersion  >> test.
